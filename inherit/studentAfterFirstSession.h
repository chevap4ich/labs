#pragma once
#include "student.h"

class StudentAfterFirstSession : public Student {
public:
    StudentAfterFirstSession() = delete;
    StudentAfterFirstSession(char* _name, unsigned int _course, unsigned int _group, unsigned int _recordBookNumber, std::vector<unsigned int> _firstSessionMarks);
    StudentAfterFirstSession(Student s, std::vector<unsigned int> _firstSessionMarks); //нужно ли чтобы сохранялся id при копировании?
    std::vector<unsigned int> getFirstSessionMarks() const;
    void setFirstSessionMarks(std::vector<unsigned int> marks);
    void StudentAfterFirstSession::setFirstSessionMark(unsigned int mark, int markPlace);
    double averageMark() override;
    ~StudentAfterFirstSession(){};
protected:
    std::vector<unsigned int> firstSessionMarks;
};

std::ostream& operator<<(std::ostream &out, const StudentAfterFirstSession s);