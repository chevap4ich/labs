#include "student.h"
#include "studentAfterFirstSession.h"
#include "studentAfterSecondSession.h"


Student::Student(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber) {
    name = new char[15];
    std::strcpy(name, _name);
    course = _course;   
    group = _group;
    const unsigned int recordBookNumber = _recordBookNumber;
    id = _id;
    _id += 1;
}

Student::Student(const Student &other){
    name = new char[15];
    std::strcpy(name, other.name);
    course = other.course;
    group = other.group;
    const unsigned int recordBookNumber = other.recordBookNumber;
    id = _id;
    _id += 1;
}

char* Student::getName() const {
    return name;
}

unsigned int Student::getCourse() const {
    return course;
}

unsigned int Student::getGroup() const {
    return group;
}

unsigned int Student::getRecordBookNumber() const {
    return recordBookNumber;
}

int Student::getId() const {
    return id;
}

void Student::setName(char* _name) {
    std::strcpy(name, _name);
}

void Student::setCourse(unsigned int _course) {
    course = _course;
}

void Student::setGroup(unsigned int _group) {
    group = _group;
}

double Student::averageMark(){
    throw;
}

std::ostream& operator<<(std::ostream &out, const Student s){
    out << "Id: " << s.getId() << '\n';
    out << "Name: " << s.getName() << '\n';
    out << "Course: " << s.getCourse() << '\n';
    out << "Group: " << s.getGroup() << '\n';
    out << "Record book number: " << s.getRecordBookNumber() << '\n';
    return out;
}

double averageMarkInGroupAfterFirstSession(std::vector<Student*> &students, unsigned int group){
    int studentsAfterSessions = 0;
    double sumOfAvgMarks = 0;
    for(Student* student : students){
        if (student->getGroup() == group){
            if (typeid(*student) == typeid(StudentAfterFirstSession)){
                sumOfAvgMarks += student->averageMark();
                studentsAfterSessions++;
            }
            else if (typeid(*student) == typeid(StudentAfterSecondSession)){
                StudentAfterSecondSession* student1 = (StudentAfterSecondSession*)student;
                double sumOfMarks = 0;
                for(unsigned int mark : student1->getFirstSessionMarks()){
                    sumOfMarks += mark;
                }
                sumOfAvgMarks += sumOfMarks / 4;
                studentsAfterSessions++;
            }
        }
    }
    if (studentsAfterSessions == 0){
        return 0;
    }
    else {
        return sumOfAvgMarks / studentsAfterSessions;
    }    
}

double averageMarkInGroupAfterSecondSession(std::vector<Student*> &students, unsigned int group){
    int studentsAfterSecondSession = 0;
    double sumOfAvgMarks = 0;
    for(Student* student : students){
        if (student->getGroup() == group){
            if (typeid(*student) == typeid(StudentAfterSecondSession)){
                sumOfAvgMarks += student->averageMark();
                studentsAfterSecondSession++; 
            }
        }
    }
    if (studentsAfterSecondSession == 0){
        return 0;
    }
    else{
        return sumOfAvgMarks / studentsAfterSecondSession;
    }
}

double averageMarkOfStudents(std::vector<Student*> &students){
    int marksNumber = 0;
    double sumOfMarks = 0;
    for(Student* student : students){
        if(typeid(*student) == typeid(Student)){
            continue;
        }
        else if(typeid(*student) == typeid(StudentAfterFirstSession)){
            StudentAfterFirstSession *student1 = (StudentAfterFirstSession*)student;
            std::vector<unsigned int> marks = student1->getFirstSessionMarks();
            for(unsigned int mark : marks){
                sumOfMarks += mark;
                marksNumber++;
            }
        }
        else if (typeid(*student) == typeid(StudentAfterSecondSession)){
            StudentAfterSecondSession *student1 = (StudentAfterSecondSession*)student;
            std::vector<unsigned int> marks1 = student1->getFirstSessionMarks();
            std::vector<unsigned int> marks2 = student1->getSecondSessionMarks();
            for(unsigned int mark : marks1){
                sumOfMarks += mark;
                marksNumber++;
            }
            for(unsigned int mark : marks2){
                sumOfMarks += mark;
                marksNumber++;
            }
        }
    }
    if (marksNumber == 0){
        std::cout << "Threre are no students with marks" << '\n';
        return 0;
    }
    return sumOfMarks / marksNumber;
}