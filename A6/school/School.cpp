#include "School.h"

#include "../util/UtilVector.h"
#include "../util/UtilString.h"
#include <iostream>

using namespace School;

// Course
Course* Course::enroll(Student* s) {
    this->students.push_back(s);
    s->addCourse(this);
    return this;
}
bool Course::contains(Student* student) {
    return UtilVector::contains(students, student);
}
void Course::printCourse() {
    std::cout << "Course Name: " << this->name << std::endl;
    std::cout
    << "Students: "
    << UtilString::vectorAsStringFunc(
        students, std::function<std::string(Student*&)>([](Student*& s) { return s->name; })
    )
    << std::endl;
}

// CourseManager
Course* CourseManager::addCourse(const std::string& name) {
    auto course = new Course(name);
    courses.push_back(course);
    return course;
}
Course* CourseManager::addCourse(Course* course) {
    courses.push_back(new Course(*course));
    delete course;
    return course;
}
const std::vector<Course*> CourseManager::getCoursesOfStudent(Student* student) {
    std::vector<Course*> result;
    for(Course* c : courses) {
        if(c->contains(student)) {
            result.push_back(c);
        }
    }
    return result;
}
const std::vector<Course*>& CourseManager::getCourses() {
    return courses;
}

// Student
void Student::updateAllCourses(CourseManager& cm) {
    courses = cm.getCoursesOfStudent(this);
}
bool Student::addCourse(Course* c) {
    if(UtilVector::contains(courses, c)) {
        return false;
    }
    courses.push_back(c);
    return true;
}
bool Student::removeCourse(Course* c) {
    return UtilVector::removeElement(courses, c);
}
void Student::printStudent() {
    std::cout << "Student Name: " << this->name << std::endl;
    std::cout
    << "Courses: "
    << UtilString::vectorAsStringFunc(
        courses, std::function<std::string(Course*&)>([](Course*& c) { return c->name; })
    )
    << std::endl;
}

// StudentManager
Student* StudentManager::addStudent(const std::string& name) {
    auto result = new Student(name);
    students.push_back(result);
    return result;
}
Student* StudentManager::addStudent(Student* student) {
    students.push_back(new Student(*student));
    delete student;
    return student;
}
void StudentManager::updateAllStudents(CourseManager& cm) {
    for(Student* student : students) {
        student->updateAllCourses(cm);
    }
}
const std::vector<Student*>& StudentManager::getStudents() {
    return students;
}