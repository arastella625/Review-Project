#include "grade_book.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    
     /*
    // GOAL: beat all of these test cases successfully
    gradebook.read_File("grades.txt");
    // TO-DO: implement run_task and make it a variadic method?
    gradebook.run_task("individual", "assignments", 4) // outputs the individual grade of assignment #4
    gradebook.run_task("category", "labs"); // outputs category total for labs
    gradebook.run_task("course"); // outputs the entire course grade
    */
    
    //read in file name from CLA
    std::string file_name = argv[1];

    //create a Grade_book object
    Grade_book grades;

    //read in the file to get the grades
    grades.read_file(file_name);

    //if argc is 5 then store CLAs and call individual method 
    //and output task method
    if(argc == 5){

        std::string task = argv[3];
        int task_num = std::stoi(argv[4]);
        grades.print_individual(task, task_num);
        
    }
    //if argc is 3 then store CLAs and call category method
    //and output task method
    else if(argc == 3){

        std::string task = argv[2];
        grades.print_category(task);

    }
    //else run the course and output task method
    else{

        grades.print_course();
    }

    bool output = true;
    std::string answer;
    std::string task_answer;
    int task_num_answer;
    int task_grade;

    while(output){

        std::cout << "\n";

        std::cout << "Does the user want to make changes to a grade? Please type either Y or N: ";

        std::cin >> answer;

        if(answer == "N"){

            output = false;
        }

        std::cout << "What category will you be changing? Please copy one of these choices: " << "\n";
        std::cout << "\n";
        std::cout << "\t" << "labs" << "\n";
        std::cout << "\t" << "assignments" << "\n";
        std::cout << "\t" << "projects" << "\n";
        std::cout << "\t" << "exam" << "\n";
        std::cout << "\n" << "Category: ";

        std::cin >> task_answer;

        std::cout << "\n";

        std::cout << "Which " << task_answer << " grade will you be changing?" << "\n" << "*Reminder - please use indexed numbers: ";

        std::cin >> task_num_answer;

        std::cout << "\n";

        std::cout << "What will be the grade you are changing to?: ";

        std::cin >> task_grade;

        std::cout << "Changing grade now ... " << std::endl;

        std::cout << "\n";

        grades.output_file(file_name, task_answer, task_num_answer, task_grade);

        std::cout << "Your grade has been changed! This program will now end." << "\n" << "Please re-run to use your changed grade." << std::endl;

        output = false;

    }
    return 0;
}
