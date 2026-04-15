/**
 * @file a6p2.cpp
 * @brief Student & Course Management
 * @author Hayden Holmes
 * @date April 2026
 * @version 1.0
 * 
 * Use StudentManager and CourseManager from school/School.h to manage enrolling students in courses
*/

#include "logger/Log.h"
#include <string>
#include "school/School.h" // School system

using namespace School;

int main() {

    //Log::LOG_FILTER = -1;
    Log::defaultLogger();
    Log::debug("Debug messages are enabled");

    // Init studentmanager (to keep track of pointers + deleting)
    StudentManager sm;
    Student* hayden = sm.addStudent("Hayden");
    Student* brody = sm.addStudent("Brody");
    Student* carter = sm.addStudent("Carter");
    Student* joel = sm.addStudent("Joel");

    // Init coursemanager (to keep track of pointers + deleting)
    CourseManager cm;
    Course* math = cm.addCourse("Math");
    Course* english = cm.addCourse("English");
    Course* science = cm.addCourse("Science");

    // Enroll students into classes
    math->enroll(hayden)->enroll(brody)->enroll(joel);
    english->enroll(brody)->enroll(joel)->enroll(carter);
    science->enroll(carter)->enroll(hayden);

    // Print students first
    std::cout << "Students:" << std::endl;
    for(Student* student : sm.getStudents()) {
        student->printStudent();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // Print courses now
    std::cout << "Courses:" << std::endl;
    for(Course* course : cm.getCourses()) {
        course->printCourse();
        std::cout << std::endl;
    }

    return 0;
    
}