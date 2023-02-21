#include "grade_book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Grade_book::Grade_book()
{

}

void Grade_book::read_file(std::string file_name)
{
    //create fstream 
    std::fstream file;
    //open the file
    file.open(file_name);
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

void Grade_book::output_file(std::string file_name, std::string task_answer, int task_num, int task_grade)
{
    //if exam just set equal to changed grade	
    if(task_answer == "exam") {

        exam = task_grade;
    }
    //otherwise go through vectors	
    else{
	//if labs, find grade and change to new grade and end loop
        if(task_answer == "labs"){
            for(int i = 0; i < labs.size(); i++){

                if(i == task_num){

                    labs[i] = task_grade;
                    break;
                }
            }
        }
	//if assignments, find grade and change to new grade and end loop    
        else if(task_answer == "assignments"){

            for(int i = 0; i < assignments.size(); i++){

                if(i == task_num){

                    assignments[i] = task_grade;
                    break;
                }
            }
        }
	//otherwise find grade in projects and change and end loop    
        else{

            for(int i = 0; i < projects.size(); i++){

                if(i == task_num){

                    projects[i] = task_grade;
                    break;
                }
            }
        }
    }

    std::ofstream file;
    file.open(file_name);
    
    //go through each vector and rewrite the grades in the file
    //with the new changed grade	
	
    for(int i = 0; i < labs.size(); i++){

        file << labs[i] << " ";
    }

    file << "\n";

    for(int i = 0; i < assignments.size(); i++){

        file << assignments[i] << " ";
    }

    file << "\n";

    for(int i = 0; i < projects.size(); i++){

        file << projects[i] << " ";
    }

    file << "\n";

    file << exam;

    file.close();

}

double Grade_book::individual(std::string task, int task_num)
{
    double grade;

    if (task == "assignments") {
        grade = assignments[task_num];
        return grade;
    } else if ( task == "labs") {
        grade = labs[task_num];
        return grade;
    } else if ( task == "projects") {
        grade = projects[task_num];
        return grade;
    } else {
        grade = exam;
        return grade;
    }

}

double Grade_book::category(std::string _category)
{
    double sum_grade = 0.0;
    
    //if (_category == "ASSIGNMENTS") {
    if (_category == 1) {   //ASSIGNMENTS
        cout << "Assignments ";
        for (int i = 0; i < assignments.size(); i++) {
            sum_grade += assignments[i];
            cout << assignments[i] << " ";
        }
        cout << "= " << sum_grade << endl;
        return sum_grade;
    }
    
    //if (_category == "LABS") {
    if (_category == 2) {   //LABS
        cout << "Labs ";
        for (int i = 0; i < labs.size(); i++) {
            sum_grade += labs[i];
            cout << labs[i] << " ";
        }
        cout << "= " << sum_grade << endl;
        return sum_grade;
    }
    
    //if (_category == "PROJECTS") {
    if (_category == 3) {  //PROJECTS
        cout << "Projects ";
        for (int i = 0; i < projects.size(); i++) {
            sum_grade += projects[i];
            cout << projects[i] << " ";
        }
        cout << "= " << sum_grade << endl;
        return sum_grade;
    }
    
    //if (_category == "EXAM") {
    if (_category == 4) {  //EXAM
        cout << "Exam ";
        sum_grade = exam;
        cout << exam << " = " << sum_grade << endl;
        return sum_grade;
    }
    
    return sum_grade;
}

double Grade_book::course()
{
	// Mikey
	double assignments_grade;
	assignments_grade = this->category(1); // fetch assignments weight
	//assignments_grade = this->category("ASSIGNMENTS"); // fetch assignments weight
	
	double labs_grade;
	labs_grade = this->category(2); // fetch labs weight
	
	double projects_grade;
	projects_grade = this->category(3); // fetch projects weight
	
	// calculate overall course grade
	// TO-DO: figure out what to replace 1000 with
	double total_grade = (this->exam + assignments_grade + labs_grade + projects_grade) / this->course_total;
	
	return total_grade;
}


void Grade_book::print_individual(std::string task, int task_num) {
    double grade = individual(task, task_num);
    std::cout << task << task_num << "grade is" << grade << "/n";
}

void print_category(std::string task) {
    double grade = category(task);
    if (task == "labs"){
        for (int i = 0; i <= labs.size(); i++){
            std::cout << "Lab " << i << ": " << labs[i] << "/n";
        }
    } else if ( task == "assignments") {
        for (int i = 0; i <= assignemnts.size(); i++){
            std::cout << "Assignement " << i << ": " << assignments[i] << "/n";
        }
    } else if (task == "projects") {
        for (int i = 0; i <= projects.size(); i++){
            std::cout << "Projects " << i << ": " << projects[i] << "/n";
        }
    } else {
        std::cout << "Exam: " << exam;
    }
	
    }

void Grade_book::print_course(){

    double final_grade = (course()/10);
    int answer;

    std::cout << "Which number would you like to see?: " << "\n";

    std::cout << "\t" << "1. All grades in each category and the course overall grade" << "\n";
    std::cout << "\t" << "2. Each category total and course overall grade" << "\n";
    std::cout << "\t" << "3. Only the course overall grade" << "\n"

    std::cout << "Answer: ";
    std::cin >> answer;
    std::cout << "\n";

    if(answer == 1){

        std::cout << "Lab Grades: ";

        for(int i=0; i < labs.size(); i++){

            std::cout << labs[i];
        }
        std::cout << "\n";

        std::cout << "Assignment Grades: ";

        for(int i=0; i < assignments.size(); i++){

            std::cout << assignments[i];
        }
        std::cout << "\n";

        std::cout << "Project Grades: ";

        for(int i=0; i < projects.size(); i++){

            std::cout << projects[i];
        }
        std::cout << "\n";

        std::cout << "Exam Grade: " << exam << "\n";

        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }

    if(answer == 2){

        std::cout << "Lab Total Grade: " << category(labs) << "\n"
        std::cout << "Assignment Total Grade: " << category(assignments) << "\n"
        std::cout << "Project Total Grade: " << category(projects) << "\n"
        std::cout << "Exam Total Grade: " << exam << "\n"
        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }

    if(answer == 3){

        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }

}
