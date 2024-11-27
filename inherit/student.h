#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>
static unsigned int _id = 1000000;

class Student {
public:
    Student() = delete;
    Student(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber);
    Student(const Student &other);
    int Student::getId () const;
    char* Student::getName() const ;
    unsigned int Student::getCourse() const;
    unsigned int Student::getGroup() const;
    unsigned int Student::getRecordBookNumber() const;
    void Student::setName(char* _name);
    void Student::setCourse(unsigned int _course);
    void Student::setGroup(unsigned int _group);
    virtual double averageMark();
    ~Student(){
        delete[]name;
    }

protected:
    char* name;
    unsigned int course;
    unsigned int group;
    unsigned int recordBookNumber;
    unsigned int id;
};

std::ostream& operator<<(std::ostream &out, const Student s);
double averageMarkInGroupAfterFirstSession(std::vector<Student*> &students, unsigned int group);
double averageMarkInGroupAfterSecondSession(std::vector<Student*> &students, unsigned int group);
double averageMarkOfStudents(std::vector<Student*> &students);
