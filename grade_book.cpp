#include "grade_book.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

Grade_book::Grade_book()
{

}

std::vector<double> Grade_book::get_labs()
{
    return labs;
}

std::vector<double> Grade_book::get_assignments()
{
    return assignments;
}

std::vector<double> Grade_book::get_projects()
{
    return projects;
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
    file.close();
}

void Grade_book::output_file(std::string file_name, std::string task_answer, int task_num, int task_grade)
{
    if(task_answer == "exam") {

        exam = task_grade;
    }
    else{

        if(task_answer == "labs"){
            for(int i = 0; i < labs.size(); i++){

                if(i == task_num){

                    //std::cout << "Changing grade from" << labs[i] << " to " << task_grade << std::endl;

                    labs[i] = task_grade;
                    break;
                }
            }
        }
        else if(task_answer == "assignments"){

            for(int i = 0; i < assignments.size(); i++){

                if(i == task_num){

                    //std::cout << "Changing grade from" << assignments[i] << " to " << task_grade << std::endl;

                    assignments[i] = task_grade;
                    break;
                }
            }
        }
        else{

            for(int i = 0; i < projects.size(); i++){

                if(i == task_num){

                    //std::cout << "Changing grade from" << projects[i] << " to " << task_grade << std::endl;

                    projects[i] = task_grade;
                    break;
                }
            }
        }
    }

    std::ofstream file;
    file.open(file_name);

    for(int i = 0; i < labs.size(); i++){

        //values << labs[i];
        //file << values.str();
        file << labs[i] << " ";
    }

    file << "\n";

    for(int i = 0; i < assignments.size(); i++){

        //values << assignments[i];
        //file << values.str();
        file << assignments[i] << " ";
    }

    file << "\n";

    for(int i = 0; i < projects.size(); i++){

        //values << projects[i];
        //file << values.str();
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
    //for(int i = 0; i < assignments.size(); i++){
    //if(task_num == assignments[i]){
    //grade = assignments[i];
    //}
    //} else if ( task == "labs"){
    //    for(int i = 0; i < labs.size(); i++){
    //        if(task_num == labs[i]){
    //            grade = labs[i];
    //            return grade;
    //        }
    //    }
    //} else if (task == "projects"){
    //    for(int i = 0; i < projects.size(); i++){
    //        if(task_num == projects[i]){
    //            grade = projects[i];
    //            return grade;
    //        }
    //    }
    //} else {
    //    if (task == "exam"){
    //        grade =
    //    }
    //}
}

//FUNCTION category: returns all grades from the category and category total
/*
Labs 20 20 20 20 20 20 20 20 20 20 
Assignments  50 50 50 50 
Projects 150 350 
Exam 100 

std::vector<double> labs;
std::vector<double> assignments;
std::vector<double> projects;
double exam;
*/
//double Grade_book::category(std::string _category)
double Grade_book::category(int _category)
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

void Grade_book::run_task()
{
  // TO-DO: implement variadic functionality?
  // TO-DO: 'driver method' of Grade_Book class
  // we will begin building this once we know that ::individual(), ::category(), and ::course() are all properly working
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
