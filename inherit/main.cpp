#include "student.h"
#include "studentAfterFirstSession.h"
#include "studentAfterSecondSession.h"
#include <iostream>

int main() {
    Student s1("alex", 1, 1, 234523452);
    std::cout << s1.getId() << '\n';
    Student s2("alex", 1, 1, 234523452);
    std::cout << s2.getId() << '\n';
    Student s3("alex", 1, 1, 234523452);
    std::cout << s3.getId() << '\n';
    std::vector<unsigned int> marks {1, 2, 3, 4};
    StudentAfterFirstSession s4("ghghghhg", 2, 1, 394369523, marks);
    StudentAfterFirstSession s5(s1, marks);
    StudentAfterSecondSession s6("abcd", 4, 1, 1234134, {1, 2, 3, 4}, {10, 10, 10, 10, 10});
    StudentAfterSecondSession s7("aashdfl", 4, 1, 1234134, {4, 4, 4, 4}, {6, 1, 1, 1, 1});
    std::cout << s4.getId() << '\n';
    std::cout << s5.getId() << '\n';
    std::vector<unsigned int> marks1 = s6.getSecondSessionMarks();
    std::cout << marks1[0] << '\n';
    std::cout << s4.averageMark() << '\n';
    std::vector<Student*> students;
    Student* s1_p = &s1;
    Student* s4_p = &s4;
    Student* s6_p = &s6;
    Student* s7_p = &s7;
    students.push_back(s1_p);
    students.push_back(s4_p);
    students.push_back(s6_p);
    students.push_back(s7_p);
    std::cout << averageMarkInGroupAfterFirstSession(students, 1) << '\n';
    std::cout << averageMarkInGroupAfterSecondSession(students, 1) << '\n';
    std::cout << averageMarkOfStudents(students) << '\n';
}


