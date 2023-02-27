/* @project Gradebook Review Project
 * @desc A gradebook utilizing a points-achieved system to help track progress throughout CSC212
 * @class URI CSC212
 * @professor Jonathan Schrader
 * @date 26 February 2023
 * @group_members Amber Rastella, Giorgio Florentino, Junsheng Wu, Michael Tedeschi
 */
#include "gradebook.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    Grade_Book grades; // instantiate a Grade_book object
    grades.initialize(argc, argv); // call main driver method for Grade_book with CLA as parameters

    return 0;
}
