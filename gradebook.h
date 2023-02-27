#ifndef GRADE_BOOK
#define GRADE_BOOK
#include <vector>
#include <string>

class Grade_Book {
    private:
        std::vector<double> labs;        // container for lab grades
        std::vector<double> assignments; // container for assignment grades
        std::vector<double> projects;    // container for project grades
        double exam;                     // final exam grade
    public:
        Grade_Book(); // default constructor
        // +==== FILE I/O METHODS =====+ //
        void read_file(std::string fileName); // reads input file and stores grades in proper containers
        void modify_file(std::string fileName, std::string categoryName, int categoryIndex, int newGrade); // modifies a grade in the input .txt file
        // +==== GRADE CALCULATION METHODS ====+ //
        double individual(std::string categoryName, int categoryIndex); //returns an individual grade from a category
        double category(std::string categoryName); // returns total points achieved for a category
        double course(); // returns total points achieved for the entire course
        // +==== DISPLAY / "USER INTERFACE" METHODS ====+ //
        void print_individual(std::string categoryName, int categoryIndex); // outputs an individual grade from a category
        void print_category(std::string categoryName); // outputs each individual grade from a category, plus the category total
        void print_course(); // prompts user for how they'd like to see their overall course achievement, and displays appropriately
        // +==== MAIN DRIVER METHOD ====+ //
        void initialize(int argc, char* argv[]); // main driver function for the class. receives CLA as parameters
};

#endif /* GRADE_BOOK */
