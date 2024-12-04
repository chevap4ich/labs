#include "studentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber, std::vector<unsigned int> _firstSessionMarks) : Student (_name, _course, _group, _recordBookNumber){
    firstSessionMarks = _firstSessionMarks;
}

StudentAfterFirstSession::StudentAfterFirstSession(const Student &s, std::vector<unsigned int> _firstSessionMarks) : Student (s.getName(), s.getCourse(), s.getGroup(), s.getRecordBookNumber()){
    firstSessionMarks = _firstSessionMarks;
}

std::vector<unsigned int> StudentAfterFirstSession::getFirstSessionMarks() const {
    return firstSessionMarks;
}

void StudentAfterFirstSession::setFirstSessionMarks(std::vector<unsigned int> marks){
    for (int i = 0; i < 4; i++){
        firstSessionMarks[i] = marks[i];
    }
}

void StudentAfterFirstSession::setFirstSessionMark(unsigned int mark, int markPlace){
    firstSessionMarks[markPlace] = mark;
}

double StudentAfterFirstSession::averageMark(){
    double sum = 0;
    for(auto mark : firstSessionMarks){
        sum += mark;
    }
    return sum / 4;
}

std::ostream& operator<<(std::ostream &out, const StudentAfterFirstSession s){
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
    return out;
}
