#pragma once
#include <iostream>
#include <string>
/*�������� ��������� � ������������ � ��������� �������. ��� ������
������������� ����������� �� ���������, ����������� � �����������,
����������� �� ������� ������������� ����������, ����������� �����������,
����������, ������: ���������, ����������� ����� ������ � ������ ��������
�������, ������������� �������. ��� �������� �������� ������ ������������
������������ ������. �������� ������ � ������� ������ ������ ���������� �
��������� ������.*/
/*������� ����� � ������ NOTE, ���������� ����:
- ������� � ���;
- ����� ��������;
- ���� �������� (������ �� ���� �����).
�������� ���������, ����������� ��������� ��������:
- ���� � ���������� ������ ������ ���� NOTE;
- ����� �� ����� ���������� � �����, ��� ��� �������� ���������� �� �����,
�������� �������� ������� � ����������;
- ���� ����� ����� ���, ������� ��������������� ���������.*/

class Note
{
private:
	std::string name;
	std::string surname;
	std::string phoneNumber;
	int* birthDate = new int[3];
public:
	Note();
	Note(std::string _name, std::string _surname, std::string _phoneNumber, int birthDay, int birthMonth, int birthYear);
	Note(std::string _name, std::string _surname, std::string _phoneNumber, int* _birthDate);
	Note(std::string _name, std::string _surname);
	Note(const Note& note);
	~Note();
	std::string GetInfoString();
	void SetName(std::string _name);
	void SetSurname(std::string _surname);
	void SetPhoneNumber(std::string _phoneNumber);
	void SetBirthDate(int birthDay, int birthMonth, int birthYear);
	void SetBirthDate(int* _birthDate);
	std::string GetName();
	std::string GetSurname();
	std::string GetPhoneNumber();
	int* GetBirthDate();
	int GetBirthMonth();	
};

