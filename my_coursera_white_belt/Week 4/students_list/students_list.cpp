#include <iostream>
#include <string>
#include <vector>


struct Student 
{
    std::string first_name;
    std::string last_name;

    int day;
    int month;
    int year;
};

int main() 
{
    int n;
    std::cin >> n;

    std::string first_name, last_name;
    int day, month, year;
    std::vector<Student> students;

    for (size_t i = 0; i < n; ++i) 
    {
        std::cin >> first_name >> last_name >> day >> month >> year;

        students.push_back(Student{
          first_name,
          last_name,
          day,
          month,
          year
            });
    }

    int m;
    std::cin >> m;
    std::string query;
    int student_number;

    for (int i = 0; i < m; ++i) 
    {
        std::cin >> query >> student_number;
        --student_number;

        if (query == "name" && student_number >= 0 && student_number < n) 
        {
            std::cout << students[student_number].first_name << " "
                << students[student_number].last_name << std::endl;
        }
        else if (query == "date" && student_number >= 0 && student_number < n) 
        {
            std::cout << students[student_number].day << "."
                << students[student_number].month << "."
                << students[student_number].year << std::endl;
        }
        else 
        {
            std::cout << "bad request" << std::endl;
        }
    }

    return 0;
}

