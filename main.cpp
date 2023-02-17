#include "grade_book.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[]){
    
    //read in file name from CLA
    std::string file_name = argv[1];

    //create a Grade_book object
    Grade_book grades;

    //read in the file to get the grades
    grades.read_file(file_name);

    //if argc is 5 then store CLAs and call individual method 
    //and output task method
    if(argc == 5){

        /*
        std::string task = argv[3];
        int task_num = std::stoi(argv[4]);
        grades.individual(task, task_num);
        grades.run_task();
        */
    }
    //if argc is 3 then store CLAs and call category method
    //and output task method
    else if(argc == 3){

        /*
        std::string task = argv[2];
        grades.category(task);
        grades.run_task();
        */
    }
    //else run the course and output task method
    else{

        /*
        grades.course();
        grades.run_task();
        */
    }
    /*
    // GOAL: beat all of these test cases successfully
    gradebook.read_File("grades.txt");
    // TO-DO: implement run_task and make it a variadic method?
    gradebook.run_task("individual", "assignments", 4) // outputs the individual grade of assignment #4
    gradebook.run_task("category", "labs"); // outputs category total for labs
    gradebook.run_task("course"); // outputs the entire course grade
    */
    return 0;
}
