# Review-Project

This will house all documentation for the Review Project for CSC 212

## Description

This program will allow a user to evaluate individual deliverables from CSC 212 to provide an 
output of semester course grades. Viewable outputs will include:

 individual: returns an individual deliverable name and grade

 category: returns all grades from the category and category total

 course: ability to return each of the following:

    all grades within their respective categories and a course overall

    only category totals and course overall

    only the course overall 

At the end of the program the user has an option to change any grade they would like.


## Instructions

Here the user shall exercise their due diligence beneficial to a successful 
running program.

There are 3 files associated with this program. One header file, and two
.cpp files. When compiling you will need all three in the local directory of your
choice depending on the IDE you are using.

You will be compiling with g++. A compilation line may look like this:

          g++ main.cpp grade_book.cpp -o prog_name

To execute this program properly you will initially be inputting CLA's as your choices. 
As usual, the order you put them in will be *critical* to the success of the program running as well
as the spelling of each of them. 
Please follow in this order:  

  1. First command will be your program name - this will be whatever name you used in compilation.
  2. Secondly, there will be a command for an input file. There are 4 sets of data within the repository. 
     The .txt files will be named as follows: "nameOfStudent_grades.txt". User will choose which data file they would 
     like to use. Proper spelling is important - program will NOT run otherwise.
  3. Thirdly, there will be a command for the type of deliverable that the user would like to see outputted. Please
     see the description for for further explanation. The user will have three choices:
     
            - individual
            - category
            - course
            
     Please type in as you see here. 
     
  4. *IF USER CHOOSES individual OR category* there will be a fourth CLA. This will be the task type that the user would like         to see outputted. The user will have four choices:
 
            - labs
            - assignments
            - projects
            - exam 
   
     Please type in as you see here.
     
   5. *IF USER CHOSE individual* there will be one last CLA. This will be the number of the task with which the user would like       to be outputted. IMPORTANT: this number will act as an *indexed* number. For example:
  
            - There are a total of 10 lab grades. Normally this is counted 1 - 10. However, this program
              will count 0 - 9. If the user wanted the 5th lab grade, they would input the number 4. 
            - There are a total of 4 assignment grades. This will be counted 0 - 3. If the user wanted the 2nd assignment                     grade, they will input the number 1.
            - There are a total of 2 project grades. This will be counted 0 - 1. If the user wanted the 1st project grade, they               will input the number 0.
            - There is only 1 exam grade. The user will input 0 for this category.
            - 
      Inputting numbers that are not within the index count for their category will cause the program to not run.

After outputting the deliverable chosen by the user, the program will prompt the user about making changes to the grades within the input file given in the command line. Directions are in the ouput of the terminal but to make it clear please read the following questions as will be seen in the output:

    1. Does the user want to make changes to a grade? Please type either Y or N
    - The only acceptable answers are Y or N. Do not spell out Yes or No. If N, the program will end.
    
    2. What category will you be changing? Please copy one of these choices:
    - labs
    - assignments
    - projects
    - exam
    Please spell exactly as seen.
    
    3. Which grade will you be changing? *Reminder - please use indexed numbers*
    - Again, as the question states, the only number acceptable here will follow the same rules as the CLA in #5.
    
    4. What will be the grade you are changing to?
    - This number will be a new grade number for that specific lab/assignment/project/exam. 
  
After the last question, the program will then change the grade the user entered to the new grade, overwriting the input file given. The program will then end. The user can now run the program again with the same file to work with the new grade. 
    
