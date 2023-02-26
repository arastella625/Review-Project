#ifndef GRADE_BOOK
#define GRADE_BOOK
#include <vector>
#include <string>

class Grade_book {
    private:
        std::vector<double> labs;
        std::vector<double> assignments;
        std::vector<double> projects;
        double exam;
    public:
        Grade_book();
        void read_file(std::string file_Name);
        void output_file(std::string file_name, std::string task_answer, int task_num, int task_grade);
        double individual(std::string category, int cat_num);
        double category(std::string categoryName);
        double course();
        void print_individual(std::string category, int cat_num);
        void print_category(std::string category_name);
        void print_course();
};

#endif /* GRADE_BOOK */
