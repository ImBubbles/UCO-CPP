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
    Log::debug("Creating students");
    Student* hayden = sm.addStudent("Hayden");
    Student* brody = sm.addStudent("Brody");
    Student* carter = sm.addStudent("Carter");
    Student* joel = sm.addStudent("Joel");
    Log::debug("students create");

    // Init coursemanager (to keep track of pointers + deleting)
    CourseManager cm;
    Log::debug("Creating courses");
    Course* math = cm.addCourse("Math");
    Course* english = cm.addCourse("English");
    Course* science = cm.addCourse("Science");
    Log::debug("Courses created");

    // Enroll students into classes
    Log::debug("Enrolling");
    math->enroll(hayden)->enroll(brody)->enroll(joel);
    english->enroll(brody)->enroll(joel)->enroll(carter);
    science->enroll(carter)->enroll(hayden);
    Log::debug("Enrolled");

    // Print students first
    Log::debug("Printing students");
    std::cout << "Students:" << std::endl;
    for(Student* student : sm.getStudents()) {
        student->printStudent();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // Print courses now
    Log::debug("Printing courses");
    std::cout << "Courses:" << std::endl;
    for(Course* course : cm.getCourses()) {
        course->printCourse();
        std::cout << std::endl;
    }

    return 0;
    
}