#include "grade_book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Grade_Book::Grade_Book(){
  course_total = 1000;
}

void Grade_Book::read_File(std::string file_Name){
  //A
}

double Grade_Book::individual(int task, int task_num){
  double grade;
  
  //If statements for four options
  //Error Handling 
  //G
  
  return grade;
}

double Grade_Book::category(str task){
  // ex task = assignments 
  sum_grade=0;
    for(i=0, i< "name from read file  "; i++){
      sum_grade = "name from read file  " [i] + sum_grade
}
return sum_grade
  std::cout << "total of the '" << task <<"is "<< sum_grade << "'.\n";

  std::cout ," is: ",

double Grade_Book::course(){
	// Mikey
	double assignments_grade;
	assignments_grade = this->category(1); // fetch assignments weight
	
	double labs_grade;
	labs_grade = this->category(2); // fetch labs weight
	
	double projects_grade;
	projects_grade = this->category(3); // fetch projects weight
	
	// calculate overall course grade
	// TO-DO: figure out what to replace 1000 with
	double total_weight = (this->exam + assignments_grade + labs_grade + projects_grade) / 1000;
	
	std::cout << "Your final course grade, with the current inputs, is: " << total_weight << std::endl;
}

void Grade_Book::run_task(){
  // TO-DO: implement variadic functionality?
  // TO-DO: 'driver method' of Grade_Book class
  // we will begin building this once we know that ::individual(), ::category(), and ::course() are all properly working
}
  
  
