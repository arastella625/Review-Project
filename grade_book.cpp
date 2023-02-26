#include "grade_book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Grade_book::Grade_book(){
    // default constructor
}

void Grade_book::read_file(std::string file_name){
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

void Grade_book::output_file(std::string file_name, std::string task_answer, int task_num, int task_grade){
    if(task_answer == "exam"){
        exam = task_grade;
    } else {
        if(task_answer == "labs"){
            for(int i = 0; i < labs.size(); i++){
                if(i == task_num){
                    labs[i - 1] = task_grade;
                    break;
                }
            }
        } else if(task_answer == "assignments") {
            for(int i = 0; i < assignments.size(); i++){
                if(i == task_num){
                    assignments[i - 1] = task_grade;
                    break;
                }
            }
        } else {
            for(int i = 0; i < projects.size(); i++){
                if(i == task_num){
                    projects[i - 1] = task_grade;
                    break;
                }
            }
        }
    }

    std::ofstream file;
    file.open(file_name);

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

double Grade_book::individual(std::string category, int cat_num){
    double grade;

    if (category == "assignments") {
        grade = assignments[cat_num - 1]; // to-do: UPDATE READ-ME WITH THIS NUMERICS
    } else if ( category == "labs") {
        grade = labs[cat_num - 1];
    } else if ( category == "projects") {
        grade = projects[cat_num - 1];
    } else {
        grade = exam;
    }
    return grade;
}

double Grade_book::category(std::string categoryName){
    double sum_grade = 0.0;

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

double Grade_book::course(){
    double final_grade;

    for(int i = 0; i < labs.size(); i++){
        final_grade += labs[i];
    }
    for(int i = 0; i < assignments.size(); i++){
        final_grade += assignments[i];
    }
    for(int i = 0; i < projects.size(); i++){
        final_grade += projects[i];
    }
    
    final_grade += exam;
    final_grade /= 10;
    return final_grade;
}

void Grade_book::print_individual(std::string category, int cat_num) {
    double grade = individual(category, cat_num);
    std::cout << "Points achieved for " << category << " # " << cat_num << ": " << grade << std::endl;
}

void Grade_book::print_category(std::string category_name) {
    double grade = category(category_name);

    if (category_name == "labs"){
        for (int i = 0; i < labs.size(); i++){
            std::cout << "Lab " << i+1 << ": " << labs[i] << "\n";
        }
    } else if (category_name == "assignments") {
        for (int i = 0; i < assignments.size(); i++){
            std::cout << "Assignement " << i+1 << ": " << assignments[i] << "\n";
        }
    } else if (category_name == "projects") {
        for (int i = 0; i < projects.size(); i++){
            std::cout << "Projects " << i+1 << ": " << projects[i] << "\n";
        }
    } else {
        std::cout << "Final Exam: " << exam << std::endl;;
    }
    std::cout << "Overall points achieved for " << category_name << ": " << grade << std::endl;
}

void Grade_book::print_course(){
    double final_grade = course();
    int answer;

    std::cout << "Which number would you like to see?: " << "\n";

    std::cout << "\t" << "1. All grades in each category and the course overall grade" << "\n";
    std::cout << "\t" << "2. Each category total and course overall grade" << "\n";
    std::cout << "\t" << "3. Only the course overall grade" << "\n";

    std::cout << "Answer: ";
    std::cin >> answer;
    std::cout << "\n";

    if(answer == 1){
        std::cout << "Lab Grades: ";
        for(int i=0; i < labs.size(); i++){
            std::cout << labs[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Assignment Grades: ";
        for(int i=0; i < assignments.size(); i++){
            std::cout << assignments[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Project Grades: ";
        for(int i=0; i < projects.size(); i++){
            std::cout << projects[i] << " ";
        }
        std::cout << "\n";
        std::cout << "Exam Grade: " << exam << "\n";
        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }

    if(answer == 2){
        std::cout << "Lab Total Grade: " << category("labs") << "\n";
        std::cout << "Assignment Total Grade: " << category("assignments") << "\n";
        std::cout << "Project Total Grade: " << category("projects") << "\n";
        std::cout << "Exam Total Grade: " << exam << "\n";
        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }

    if(answer == 3){
        std::cout << "Course Overall Grade: " << final_grade << std::endl;
    }
}
