#include <iostream>
#include <Windows.h>

using namespace std;

//вариант 5

float F(float a, float b, float c, int x)
{
	
	if (c < 0 && b != 0)
		return a * x * x + b * b * x;
	else if (c > 0 && b == 0)
	{
		if(x + c != 0)
			return (x + a) / (x + c);
	}
	else
	{
		if(c != 0)
			return x / c;
	}
	cerr << "Error: zero division";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Вычислить функцию(if)
	float a, b, c;
	int x;
	cout << "Input a, b, c, x" << endl;
	cin >> a >> b >> c >> x;
	cout << F(a, b, c, x) << endl;
	//Написать программу, которая ждет ввода первой буквы названия месяца. В зависимости от этого определяет квартал.(switch)
	char monthLetter(0);
	cout << "ENTER THE FIRST LETTER OF ANY MONTH" << endl;
	cin >> monthLetter;
	//JFM  AMI  IAS  OND
	switch (monthLetter) 
	{
	case 'j': case 'J': case 'f': case 'F': cout << "Quarter №1"; break;
	case 'm': case 'M': cout << "Quarter №1 or Quarter №2"; break;
	case 'a': case 'A': case 'i': case 'I': cout << "Quarter №2 or Quarter №3"; break;
	case 's': case 'S': cout << "Quarter №3"; break;
	case 'o': case 'O': case 'n': case 'N': case 'd': case 'D': cout << "Quarter №4"; break;
	default: cerr << "Error: there's no such month";
	}
	cout << endl;
	//доп. задания
	/*11. Выведите на экран номер четверти, которой принадлежит точка с координатами
	(x, y), если x и y равны 0, то выводить сообщение что это точка начала координат, а если x
		или y равны нулю, то выводить сообщение какой оси координат принадлежит точка.*/
	cout << "Введите x и y" << endl;
	int y = 0; x = 0;
	cin >> x >> y;
	if (x == 0 && y == 0) 
	{
		cout << "Точка лежит в начале координат" << endl;
	}
	else if (x == 0 && y != 0 || y == 0 && x != 0)
	{
		if (x == 0)
			cout << "Точка лежит на оси ординат" << endl;
		else
			cout << "Точка лежит на оси абцисс" << endl;
	}
	else
	{
		if		(x > 0 && y > 0) cout << "Точка принадлежит 1-й координатной четверти" << endl;
		else if (x < 0 && y > 0) cout << "Точка принадлежит 2-й координатной четверти" << endl;
		else if (x < 0 && y < 0) cout << "Точка принадлежит 3-й координатной четверти" << endl;
		else if (x > 0 && y < 0) cout << "Точка принадлежит 4-й координатной четверти" << endl;
	}

	/*Для целого числа k от 1 до 99 напечатать фразу «Мне k лет», учитывая при этом,
что при некоторых значениях k слово «лет» надо заменить на слово «год» или «года».
Например, 11 лет, 22 года, 51 год.*/
	int age = 0;
	cout << "Введите возраст" << endl;
	cin >> age;
	cout << "Мне " << age;
	switch (age % 10)
	{
	case 1: 
		age == 11 ? cout << " лет" : cout << " год"; break;
	case 2: case 3: case 4:
		age == 12 || age == 13 || age == 14 ? cout << " лет" : cout << " года";	break;
	default: cout << " лет"; break;
	}
	return 0;
}
