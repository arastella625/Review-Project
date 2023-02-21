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
        const double course_total = 1000;
        
    public:
        Grade_book();
        void read_file(std::string file_Name);
        void output_file(std::string file_name, std::string task_answer, int task_num, int task_grade);
        double individual(std::string task, int task_num);
        double category(std::string _category);
        double course();
        void print_individual();
        void print_category();
        void print_course();
};
#endif /* GRADE_BOOK */
