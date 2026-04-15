#pragma once
#include <vector>
#include <string>

namespace School {
    class Student;
    class Course {
        std::vector<Student*> students;
        public:
        const std::string name;
        Course(const std::string& name) : name(name) {}
        Course* enroll(Student* s);
        bool contains(Student* student);
        void printCourse();
    };
    class CourseManager {
        std::vector<Course*> courses;
        public:
        CourseManager() {}
        CourseManager(const CourseManager&) = delete; // Ensure copying is disabled to avoid unsafe deconstruction
        CourseManager operator=(const CourseManager&) = delete; // Ensure copying is disabled to avoid unsafe deconstruction
        ~CourseManager() {
            for(Course* ptr : courses) {
                delete ptr;
            }
        }
        Course* addCourse(const std::string& name);

        // Will delete the old pointer and create a new one to ensure nothing else is watching it
        // Could just use std::unique_ptr but I don't like doing that for some reason
        Course* addCourse(Course* course); 
        const std::vector<Course*> getCoursesOfStudent(Student* student);
        const std::vector<Course*>& getCourses();
    };
    class Student {
        std::vector<Course*> courses; // Should be considered more of a cache than true bidirectional ownership because it's unsafe to do so
        public:
        const std::string name;
        Student(const std::string& name) : name(name) {}
        void updateAllCourses(CourseManager& cm);
        bool addCourse(Course* c);
        bool removeCourse(Course* c);
        void printStudent();
    };
    class StudentManager {
        std::vector<Student*> students;
        public:
        StudentManager() {}
        StudentManager(const StudentManager&) = delete; // Ensure copying is disabled to avoid unsafe deconstruction
        StudentManager operator=(const StudentManager&) = delete; // Ensure copying is disabled to avoid unsafe deconstruction
        ~StudentManager() {
            for(Student* ptr : students) {
                delete ptr;
            }
        }
        Student* addStudent(const std::string& name);

        // Will delete the old pointer and create a new one to ensure nothing else is watching it
        // Could just use std::unique_ptr but I don't like doing that for some reason
        Student* addStudent(Student* student);
        void updateAllStudents(CourseManager& cm);
        const std::vector<Student*>& getStudents();
    };
}