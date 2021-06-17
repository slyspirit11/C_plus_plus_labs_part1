#include "Note.h"

Note::Note()
{
	SetName("Имя");
	SetSurname("Фамилия");
	SetPhoneNumber("123456789");
	SetBirthDate(0, 0, 0);
}

Note::Note(std::string _name, std::string _surname, std::string _phoneNumber, int birthDay, int birthMonth, int birthYear)
{
	SetName(_name);
	SetSurname(_surname);
	SetPhoneNumber(_phoneNumber);
	SetBirthDate(birthDay, birthMonth, birthYear);
}

Note::Note(std::string _name, std::string _surname, std::string _phoneNumber, int* _birthDate)
{
	SetName(_name);
	SetSurname(_surname);
	SetPhoneNumber(_phoneNumber);
	SetBirthDate(_birthDate);
}

Note::Note(std::string _name, std::string _surname)
{
	SetName(_name);
	SetSurname(_surname);
	SetPhoneNumber("123456789");
	SetBirthDate(0, 0, 0);
}

Note::Note(const Note& note)
{
	this->name = note.name;
	this->surname = note.surname;	
	this->phoneNumber = note.phoneNumber;
	this->birthDate[0] = note.birthDate[0];
	this->birthDate[1] = note.birthDate[1];
	this->birthDate[2] = note.birthDate[2];
}

Note::~Note()
{
	delete[] birthDate;
}

void Note::SetName(std::string _name)
{
	name = _name;
}

void Note::SetSurname(std::string _surname)
{
	surname = _surname;
}

void Note::SetPhoneNumber(std::string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

void Note::SetBirthDate(int birthDay, int birthMonth, int birthYear)
{
	birthDate[0] = birthDay;
	birthDate[1] = birthMonth;
	birthDate[2] = birthYear;
}

void Note::SetBirthDate(int* _birthDate)
{
	birthDate[0] = _birthDate[0];
	birthDate[1] = _birthDate[1];
	birthDate[2] = _birthDate[2];
}

std::string Note::GetName()
{
	return name;
}

std::string Note::GetSurname()
{
	return surname;
}

std::string Note::GetPhoneNumber()
{
	return phoneNumber;
}

int* Note::GetBirthDate()
{
	int* date = new int[3];
	date[0] = birthDate[0];
	date[1] = birthDate[1];
	date[2] = birthDate[2];
	return date;
}

int Note::GetBirthMonth()
{
	return birthDate[1];
}

std::string Note::GetInfoString()
{
	std::string info = "Имя: " + name + "\n" +
					   "Фамилия: " + surname + "\n" +
					   "Номер телефона: " + phoneNumber + '\n' +
					   "Дата рождения: " + std::to_string(birthDate[0]) + '.'
										 + std::to_string(birthDate[1]) + '.'
										 + std::to_string(birthDate[2]);
	return info;
}
