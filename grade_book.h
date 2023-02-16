#ifndef GRADE_BOOK
#define GRADE_BOOK
#include <vector>
#include <string>


class Grade_Book {
    private:
        std::vector<double> labs;
        std::vector<double> assignments;
        std::vector<double> projects;
        double exam;
        double user_total;
        const double course_total;
    
    public:
        Grade_Book();
        void read_File(std::string file_Name);
        double individual();
        double category();
        double course();
        void run_task();
}

#endif /* GRADE_BOOK */
