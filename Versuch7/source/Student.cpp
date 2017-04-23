#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

/**
 * @brief returns the MatNr
 * @return matNr
 */
unsigned int Student::getMatNr() const
{
	return this->matNr;
}

/**
 * @brief returns the Name
 * @return Name
 */
std::string Student::getName() const
{
	return this->name;
}

/**
 * @brief returns BirthDate
 * @return BirthDate
 */
std::string Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}

/**
 * @brief returns the Address
 * @return Address
 */
std::string Student::getAddress() const
{
	return this->address;
}

/**
 * @brief print the student information to an ostream
 * @param out the stream to be streamed to
 * @return the stream
 */
std::ostream& Student::print(std::ostream &out) const
{
    out << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
              << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
              << std::endl;
    return out;
}


bool Student::operator == (const Student &student) const
{
	if(this->getMatNr() == student.getMatNr()) return true;
	else return false;
}

bool Student::operator == (const int matNr) const
{
	if(this->getMatNr() == matNr) return true;
	else return false;
}

bool Student::operator > (const Student &student) const
{
	if(this->getMatNr() > student.getMatNr()) return true;
	else return false;
}
bool Student::operator < (const Student &student) const
{
	if(this->getMatNr() < student.getMatNr()) return true;
	else return false;
}
