#include "grade_book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Grade_book::Grade_book(){

}

std::vector<double> Grade_book::get_labs(){

    return labs;
}
std::vector<double> Grade_book::get_assignments(){

    return assignments;
}
std::vector<double> Grade_book::get_projects(){

    return projects;
}

void Grade_book::read_file(std::string file_name){

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

    /*
    std::cout << "Lab Grades: ";
    for(int i = 0; i < labs.size(); i++){

        std::cout << get_labs()[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Assignment Grades: ";
    for(int i = 0; i < assignments.size(); i++){

        std::cout << get_assignments()[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Project Grades: ";
    for(int i = 0; i < projects.size(); i++){

        std::cout << get_projects()[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Exam Grade: " << exam << std::endl;
    */
}

double Grade_book::individual(std::string task, int task_num){
  double grade;
  
  //If statements for four options
  //Error Handling 
  //G
  
  return grade;
}

double Grade_book::category(std::string task){
    double sum_grade;
    /*
  i=0;
  sum=0;
  while (i<task.size){
    sum_grade = size[i]+sum_grade
    i++
  //add all tasks in specificcategory
  //Returns all output
  */
/*
	// ex task = assignments 
  sum_grade=0;
    for(i=0, i< "name from read file  "; i++){
      sum_grade = "name from read file  " [i] + sum_grade
	      std::cout << "total of the '" << task <<"is "<< sum_grade << "'.\n";

  std::cout ," is: ",
  */
    return sum_grade;
}


double Grade_book::course(){
	// Mikey
	double assignments_grade;
	assignments_grade = this->category(1); // fetch assignments weight
	
	double labs_grade;
	labs_grade = this->category(2); // fetch labs weight
	
	double projects_grade;
	projects_grade = this->category(3); // fetch projects weight
	
	// calculate overall course grade
	// TO-DO: figure out what to replace 1000 with
	double total_grade = (this->exam + assignments_grade + labs_grade + projects_grade) / this->course_total;
	
	return total_grade;
}

void Grade_book::run_task(){
  // TO-DO: implement variadic functionality?
  // TO-DO: 'driver method' of Grade_Book class
  // we will begin building this once we know that ::individual(), ::category(), and ::course() are all properly working
}
  
  
