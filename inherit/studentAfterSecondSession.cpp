#include "studentAfterSecondSession.h"

StudentAfterSecondSession::StudentAfterSecondSession(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber, std::vector<unsigned int> _firstSessionMarks, std::vector<unsigned int> _secondSessionMarks) : StudentAfterFirstSession (_name, _course, _group, _recordBookNumber, _firstSessionMarks){
    secondSessionMarks = _secondSessionMarks;
}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterFirstSession &s, std::vector<unsigned int> _secondSessionMarks) : StudentAfterFirstSession(s.getName(), s.getCourse(), s.getGroup(), s.getRecordBookNumber(), s.getFirstSessionMarks()){
    secondSessionMarks = _secondSessionMarks;
}

std::vector<unsigned int> StudentAfterSecondSession::getSecondSessionMarks() const {
    return secondSessionMarks;
}

void StudentAfterSecondSession::setSecondSessionMarks(std::vector<unsigned int> marks){
    for (int i = 0; i < 5; i++){
        secondSessionMarks[i] = marks[i];
    }
}

void StudentAfterSecondSession::setSecondSessionMark(unsigned int mark, int markPlace){
    secondSessionMarks[markPlace] = mark;
}

double StudentAfterSecondSession::averageMark(){
    double sum = 0;
    for(auto mark : firstSessionMarks){
        sum += mark;
    }
    for(auto mark : secondSessionMarks){
        sum += mark;
    }
    return sum / 9;
}

std::ostream& operator<<(std::ostream &out, const StudentAfterSecondSession s){
    out << "Id: " << s.getId() << '\n';
    out << "Name: " << s.getName() << '\n';
    out << "Course: " << s.getCourse() << '\n';
    out << "Group: " << s.getGroup() << '\n';
    out << "Record book number: " << s.getRecordBookNumber() << '\n';
    out << "Marks after first session: ";
    for (int i = 0; i < 4; i++){
        out << s.getFirstSessionMarks()[i] << ", ";
    }
    out << '\n';
    out << "Marks after second session: ";
    for (int i = 0; i < 4; i++){
        out << s.getSecondSessionMarks()[i] << ", ";
    }
    out << '\n';
    return out;
}