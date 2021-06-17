#pragma once
#include <iostream>
#include <string>
/*Написать программу в соответствии с вариантом задания. Для класса
предусмотреть конструктор по умолчанию, конструктор с параметрами,
конструктор со списком инициализации переменных, конструктор копирования,
деструктор, методы: изменения, отображения полей класса и методы согласно
задания, дружественные функции. Для хранения объектов класса использовать
динамический массив. Описание класса и методов класса должны находиться в
отдельном модуле.*/
/*Описать класс с именем NOTE, содержащий поля:
- фамилия и имя;
- номер телефона;
- дата рождения (массив из трех чисел).
Написать программу, выполняющую следующие действия:
- ввод с клавиатуры данных класса типа NOTE;
- вывод на экран информации о людях, чьи дни рождения приходятся на месяц,
значение которого введено с клавиатуры;
- если таких людей нет, вывести соответствующее сообщение.*/

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

