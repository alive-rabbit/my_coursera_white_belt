#include <iostream>
#include <string>

struct Specialization 
{
    explicit Specialization(const std::string& new_value)
    {
        value = new_value;
    }
    std::string value;
};

struct Course 
{
    explicit Course(const std::string& new_value)
    {
        value = new_value;
    }
    std::string value;
};

struct Week 
{
    explicit Week(const std::string& new_value)
    {
        value = new_value;
    }
    std::string value;
};

struct LectureTitle 
{
    LectureTitle(const Specialization& new_specialization,
        const Course& new_course,
        const Week& new_week) 
    {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
    std::string specialization;
    std::string course;
    std::string week;
}; 