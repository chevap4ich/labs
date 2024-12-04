#pragma once 
#include "studentAfterFirstSession.h"

class StudentAfterSecondSession : public StudentAfterFirstSession{
public:
    StudentAfterSecondSession() = delete;
    StudentAfterSecondSession(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber, std::vector<unsigned int> _firstSessionMarks, std::vector<unsigned int> _secondSessionMarks);
    StudentAfterSecondSession(const StudentAfterFirstSession &s, std::vector<unsigned int> _secondSessionMarks); 
    std::vector<unsigned int> getSecondSessionMarks() const;
    void setSecondSessionMarks(std::vector<unsigned int> marks);
    void setSecondSessionMark(unsigned int mark, int markPlace);
    double averageMark() override;
protected:
    std::vector<unsigned int> secondSessionMarks;
};

std::ostream& operator<<(std::ostream &out, const StudentAfterSecondSession s);