#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

unsigned int Student::getMatNr()
{
	return this->matNr;
}

std::string Student::getName()
{
	return this->name;
}

std::string Student::getDateOfBirth()
{
	return this->dateOfBirth;
}

std::string Student::getAddress()
{
	return this->address;
}

void Student::print()
{
    std::cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
}
