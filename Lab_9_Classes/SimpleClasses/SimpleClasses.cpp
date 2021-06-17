#include <iostream>
#include <Windows.h>
#include "Note.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//- ввод с клавиатуры данных класса типа NOTE
	int N = 3;
	Note* notes = new Note[N];
	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << "-я запись: " << endl;
		string name, surname, phoneNumber; int birthDate[3];
		cout << "Имя: "; cin >> name;
		cout << "Фамилия: "; cin >> surname;
		cout << "Номер телефона: "; cin >> phoneNumber;
		cout << "День рождения: "; cin >> birthDate[0];
		cout << "Месяц рождения: "; cin >> birthDate[1];
		cout << "Год рождения: "; cin >> birthDate[2];
		notes[i].SetName(name); notes[i].SetSurname(surname);
		notes[i].SetPhoneNumber(phoneNumber);
		notes[i].SetBirthDate(birthDate);
	}
	
	/*- вывод на экран информации о людях, чьи дни рождения приходятся на месяц,
значение которого введено с клавиатуры*/
	//- если таких людей нет, вывести соответствующее сообщение.
	int month = 0;
	cout << "Информация о людях чьи дни рождения приходятся на месяц, введенный с клавиатуры." << endl;	
	cout << "Введите месяц:"; cin >> month; cout << endl;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (notes[i].GetBirthMonth() == month)
		{
			count++;
			cout << count << '.' << endl;
			cout << notes[i].GetInfoString() << endl;
		}
	}
	if (!count) cout << "Ни один человек не был рождён в этот месяц." << endl;

	delete[] notes;
}