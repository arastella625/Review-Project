#include "grade_book.h"
#include <iostream>


int main(int argc, char* argv[]){
    Grade_Book gradebook;
    // GOAL: beat all of these test cases successfully
    gradebook.read_File("grades.txt");
    // TO-DO: implement run_task and make it a variadic method?
    gradebook.run_task("individual", "assignments", 4) // outputs the individual grade of assignment #4
    gradebook.run_task("category", "labs"); // outputs category total for labs
    gradebook.run_task("course"); // outputs the entire course grade
    return 0;
}
