#include "gradebook.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Grade_Book::Grade_Book(){
    // default constructor
}

void Grade_Book::read_file(std::string file_name){
    // tokenizes the input file contents and populates the appropriate vectors with grade values
    std::ifstream file; //create fstream
    file.open(file_name); //open the file

    //strings to hold the lines and values
    std::string line;
    std::string token;

    //get first line of file
    if(std::getline(file, line)){
        //tokenize values with stringstream
        std::stringstream word(line);
        //while tokenizing
        while(word >> token){
            //push back into labs vector
            labs.push_back(std::stod(token));
        }
    }
    //get second line of text file
    if(std::getline(file, line)){
        //begin to tokenize the values
        std::stringstream word(line);
        //while tokenizing
        while(word >> token){
            //push back into assignments vector
            assignments.push_back(std::stod(token));
        }
    }
    //get third line of file
    if(std::getline(file, line)){
        //begin tokenizing values
        std::stringstream word(line);
        //while tokenizing
        while(word >> token){
            //push back into projects vector
            projects.push_back(std::stod(token));
        }
    }
    //get last line of file
    if(std::getline(file, line)){
       //assign it to exam
       exam = std::stod(line);
    }
   file.close();
}

void Grade_Book::modify_file(std::string fileName, std::string categoryName, int categoryIndex, int newGrade){
    // modifies the grade vectors & the input file to reflect a new individual grade for a particular category assignment #
    // logic for this part: determine which category we are updating, then update the respective grade
    if (categoryName == "exam") {
        this->exam = newGrade;
    } else if (categoryName == "labs") {
        this->labs[categoryIndex - 1] = newGrade;
    } else if (categoryName == "assignments") {
        this->assignments[categoryIndex - 1] = newGrade;
    } else if (categoryName == "projects") {
        this->projects[categoryIndex - 1] = newGrade;
    }

    // next, we need to push these updated vector values to the .txt file
    std::ofstream file;
    file.open(fileName); // open the file

    for(int i = 0; i < labs.size(); i++){ // write each respective lab grade
        file << labs[i] << " ";
    }

    file << "\n"; // move to the next line

    for(int i = 0; i < assignments.size(); i++){ // write each respective assignment grade
        file << assignments[i] << " ";
    }

    file << "\n"; // move to the next line

    for(int i = 0; i < projects.size(); i++){ // write each respective project grade
        file << projects[i] << " ";
    }

    file << "\n"; // move to the next line
    file << exam; // all that's left to do is write the exam grade & close the file
    file.close();
}

double Grade_Book::individual(std::string categoryName, int categoryIndex){
    // returns an individual grade for a particular category assignment#
    double grade;

    // logic to assign grade a correct value follows
    if (categoryName == "assignments") {
        grade = this->assignments[categoryIndex - 1];
    } else if (categoryName == "labs") {
        grade = this->labs[categoryIndex - 1];
    } else if (categoryName == "projects") {
        grade = this->projects[categoryIndex - 1];
    } else { // default case: we can assume the user wants their exam grade
        grade = this->exam;
    }
    return grade;
}

double Grade_Book::category(std::string categoryName){
    // returns the sum of all grades for a particular category
    double sum_grade = 0.0;

    // basic logic: check which category is requested, loop thru said category and sum all values
    if (categoryName == "assignments") {
        for (int i = 0; i < assignments.size(); i++) {
            sum_grade += assignments[i];
        }
    }

    if (categoryName == "labs") {
        for (int i = 0; i < labs.size(); i++) {
            sum_grade += labs[i];
        }
    }

    if (categoryName == "projects") {
        for (int i = 0; i < projects.size(); i++) {
            sum_grade += projects[i];
        }
    }

    if (categoryName == "exam") {
        sum_grade = exam;
    }

    return sum_grade;
}

double Grade_Book::course(){
    // returns the final grade of the course for all points achieved
    double final_grade;
    // all we need to do is add all of the category totals along with the exam grade, and divide by 10 to get total achievement
    final_grade = this->category("assignments") + this->category("labs") + this->category("projects") + this->exam;
    final_grade /= 10;
    return final_grade;
}

void Grade_Book::print_individual(std::string categoryName, int categoryIndex) {
    // fetches and displays an individual grade from a category
    double grade = individual(categoryName, categoryIndex);
    std::cout << "Points achieved for " << categoryName << " # " << categoryIndex << ": " << grade << std::endl;
}

void Grade_Book::print_category(std::string categoryName) {
    // displays each individual grade achieved for a category, as well as the total pts earned for that category
    double grade = category(categoryName); // store category total
    int categoryPointsPossible = 0; // we will set this to how many possible points were available for the category

    // logic: determine which category we are displaying. then, display all of the individual grades for that category.
    if (categoryName == "labs"){
        categoryPointsPossible = 200;
        for (int i = 0; i < labs.size(); i++){
            std::cout << "Lab " << i+1 << ": " << labs[i] << "\n";
        }
    } else if (categoryName == "assignments") {
        categoryPointsPossible = 200;
        for (int i = 0; i < assignments.size(); i++){
            std::cout << "Assignement " << i+1 << ": " << assignments[i] << "\n";
        }
    } else if (categoryName == "projects") {
        categoryPointsPossible = 500;
        for (int i = 0; i < projects.size(); i++){
            std::cout << "Projects " << i+1 << ": " << projects[i] << "\n";
        }
    } else {
        // if we're dealing with the 'exam' category, we only need to output the exam
        categoryPointsPossible = 100;
        std::cout << "Final Exam: " << exam << std::endl;;
    }
    // finally, display the overall pts achieved for category
    std::cout << "Overall points achieved for " << categoryName << ": " << grade << " out of " << categoryPointsPossible << " possible points" << std::endl;
}

void Grade_Book::print_course(){
    // displays the menu for ::course() related functions
    // covers all 3 sub-options for course-related grades from the "Requirements" section of the project
    double final_grade = course(); // obtain the total points achieved for the course
    int answer; // stores the option number of the function the user would like to run

    // display the menu to the user and obtain user input
    std::cout << "How would you like to view the overall course grade? Enter a number:" << "\n";

    std::cout << "\t" << "1. All grades in each category and the overall course grade" << "\n";
    std::cout << "\t" << "2. Each category total and the overall course grade" << "\n";
    std::cout << "\t" << "3. Only the overall course grade" << "\n";

    std::cout << "Choice: ";
    std::cin >> answer;
    std::cout << "\n";

    // determine which option we want to run, and perform the function
    if(answer == 1){ // all grades in each category, plus course total
        std::cout << "Lab Grades: ";
        for(int i=0; i < labs.size(); i++){ // display all lab grades
            std::cout << labs[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Assignment Grades: ";
        for(int i=0; i < assignments.size(); i++){ // display all assignment grades
            std::cout << assignments[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Project Grades: ";
        for(int i=0; i < projects.size(); i++){ // display all project grades
            std::cout << projects[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Exam Grade: " << exam << "\n"; // display final exam grade
        std::cout << "Course Overall Grade: " << final_grade << std::endl; // display overall course grade
        return; // exit ::print_course()
    }

    if(answer == 2){ // each category total achieved, plus overall course achieved
        std::cout << "Lab Total Grade: " << this->category("labs") << "\n"; // display labs total achievement
        std::cout << "Assignment Total Grade: " << this->category("assignments") << "\n"; // display assignments total achievement
        std::cout << "Project Total Grade: " << this->category("projects") << "\n"; // display projects total achievement
        std::cout << "Exam Total Grade: " << exam << "\n"; // display exam pts achieved
        std::cout << "Course Overall Grade: " << final_grade << std::endl; // display final grade achieved
        return; // exit ::print_course()
    }

    if(answer == 3){ // display only the overall course grade
        std::cout << "Course Overall Grade: " << final_grade << std::endl;
        return; // exit ::print_course()
    }
    // very basic user input sanitization... if we're still here, we can assume the user entered invalid input, and start from the top
    std::cout << "Invalid input, try again..." << std::endl;
    this->print_course();
}

void Grade_Book::initialize(int argc, char* argv[]) {
    // main driver function for Grade_Book class
    std::string fileName;
    if (argc > 1) { // we can assume the file name was provided via command line
        fileName = argv[1];
    } else { // otherwise, prompt user for it!
        std::cout << "Enter input file name: ";
        std::cin >> fileName;
        std::cout << std::endl;
    }
    std::string categoryName;
    int categoryIndex;


    //read in the file to get the grades and populate grade category vectors
    this->read_file(fileName);

    //if argc is 5 then store CLAs and call ::print_individual() method
    if(argc == 5){
        categoryName = std::string(argv[3]);
        categoryIndex = std::stoi(argv[4]);
        this->print_individual(categoryName, categoryIndex);
    }
    //if argc is 4 then store CLAs and call ::print_category() method
    if(argc == 4){
        categoryName = std::string(argv[3]);
        this->print_category(categoryName);
    }
    //if argc is 3 run the ::print_course() method
    if (argc == 3) {
        this->print_course();
    }

    bool modifying = true; // when true, the user will continue being asked if they'd like to change their grades
    char userModifyResponse; // this will store response from user if they would like to change a grade
    std::string modifyCategoryName; // will store the name of the category being changed
    int modifyCategoryIndex; // index of the category grade being changed
    int newGrade; // the new grade value

    while(modifying){ // this will execute until the user enters 'n' (no)
        std::cout << "\n";
        std::cout << "Would you like to modify the input file? Enter 'y' or 'n': " << std::endl;
        std::cin >> userModifyResponse;

        if(userModifyResponse == 'n' || userModifyResponse == 'N') {
            // the user does not wish to modify any further
            modifying = false;
            break;
        } else if (userModifyResponse == 'y' || userModifyResponse == 'Y') {
            // we do want to modify. find out which category the user would like to change
            std::cout << "Enter category to change (case sensitive!):" << "\n";
            std::cout << "\n";
            std::cout << "\t" << "labs" << "\n";
            std::cout << "\t" << "assignments" << "\n";
            std::cout << "\t" << "projects" << "\n";
            std::cout << "\t" << "exam" << "\n";
            std::cout << "\n" << "Category: ";
            std::cin >> modifyCategoryName;
            std::cout << "\n";
            if (modifyCategoryName != "exam") { // if the user changes their exam grade, we don't need an index
                std::cout << "Enter " << modifyCategoryName << " assignment number to change:" << "\n";
                std::cin >> modifyCategoryIndex;
                std::cout << "\n";
            }
            std::cout << "Enter new grade: ";
            std::cin >> newGrade; // obtain the new grade value
            std::cout << "Changing grade now ... " << std::endl;
            std::cout << "\n";
            this->modify_file(fileName, modifyCategoryName, modifyCategoryIndex, newGrade); // execute the grade change!
            std::cout << "Your grade has been changed!" << std::endl;
        }
    }
}
