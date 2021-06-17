#include <iostream>
#include <Windows.h>

using namespace std;

//5 вариант: 6, 16, 26
//6: вычислить y = tg(x)+5x^3-4x^2
//16: вычислить корень квадратный от (x^5-x^4+|x^3|);
//26: вычислить y = x^3-x^5+|x-sin(x)|+x^2
//доп.задания: 14, 20
//14: Найдите сумму цифр четырехзначного числа.
/*20: С помощь логической переменной определить: есть ли в записи четырехзначного
числа цифра n(цифра n вводиться с клавиатуры).*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float x, y;
	cout << "Введите x" << endl;
	cin >> x;
	y = tan(x) + 5 * x * x * x - 4 * x * x;
	cout << "y = tg(x)+5x^3-4x^2 = " << y << endl;
	y = sqrt(x * x * x * x * x - x * x * x * x + abs(x * x * x));
	cout << "y = sqrt(x^5-x^4+|x^3|) = " << y << endl;
	y = x * x * x - x * x * x * x * x + abs(x - sin(x)) + x * x;
	cout << "y = x^3-x^5+|x-sin(x)|+x^2 = " << y << endl;
	//дополнительные задания
	//14 Найдите сумму цифр четырехзначного числа.
	int num = 0, sum = 0;
	cout << "Введите четырёхзначное число" << endl;
	cin >> num;
	num = abs(num);
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	cout << "Сумма цифр четырехзначного числа: " << sum << endl;
	/*20: С помощь логической переменной определить: есть ли в записи четырехзначного
числа цифра n(цифра n вводиться с клавиатуры).*/
	cout << "Введите четырехзначное число и цифру" << endl;
	int n; bool in = false;
	cin >> num >> n;
	num = abs(num);
	while (num != 0 && !in)
	{
		int temp = num % 10;
		in = temp == n;
		num /= 10;
	}
	in ? cout << "Цифра " << n << " в числе есть!" : cout << "Цифры " << n << " в числе нет";
	return 0;
}