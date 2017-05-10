#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

/**
 * @brief returns the MtNr
 * @return matNr
 */
unsigned int Student::getMatNr()
{
	return this->matNr;
}

/**
 * @brief return the name
 * @return name
 */
std::string Student::getName()
{
	return this->name;
}

/**
 * @brief returns the birth date
 * @return birth date
 */
std::string Student::getDateOfBirth()
{
	return this->dateOfBirth;
}

/**
 * @brief returns the Address
 * @return address
 */
std::string Student::getAddress()
{
	return this->address;
}

/**
 * @brief prints the information of this student to cout
 */
void Student::print()
{
    std::cout << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
}
