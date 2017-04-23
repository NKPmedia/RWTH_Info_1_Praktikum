#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address);
	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getDateOfBirth() const;
	std::string getAddress() const;
	std::ostream& print(std::ostream &out) const;
	bool operator == (const Student &student) const;
	bool operator == (const int matNr) const;
	bool operator > (const Student &student) const;
	bool operator < (const Student &student) const;
private:
    unsigned int matNr;
    std::string name;
    std::string dateOfBirth;
    std::string address;
};

#endif
