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
        double user_total;
        const double course_total = 1000;
        
    public:
        Grade_book();
        std::vector<double> get_labs();
        std::vector<double> get_assignments();
        std::vector<double> get_projects();
        void read_file(std::string file_Name);
        double individual(std::string task, int task_num);
        double category(std::string task);
        double course();
        void run_task();
};



#endif /* GRADE_BOOK */
