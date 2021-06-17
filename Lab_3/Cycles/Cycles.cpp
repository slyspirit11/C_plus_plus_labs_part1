#include <iostream>
#include <Windows.h>

using namespace std;
//5 вариант

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //5.1.5
    /*Напишите программу поиска двухзначных чисел, таких, что если к сумме цифр
этого числа прибавить квадрат этой суммы, получится это число.*/
    //int digitsSum = 0;
    //for (int num = 10; num < 100; num++)
    //{
    //    int temp = num;
    //    for (; temp > 0; )
    //    {
    //        digitsSum += temp % 10;
    //        temp /= 10;
    //    }
    //    if (digitsSum + digitsSum * digitsSum == num)
    //        cout << num << endl << -num << endl;
    //    digitsSum = 0;
    //}
    //cout << endl << endl;
    //5.2.5
    /*Найти сумму ряда с точностью e, общий член которого равен an = n^2 * e^(-sqrt(n)).
    Точность считается достигнутой, если следующий член последовательности меньше заданного e*/
    double eps = 1e-3;
    //do..while
    int n = 0;
    double an = n * n * pow(exp(1), -sqrt(n)), anNext = an, sum = 0;
    do
    {
        an = anNext;
        sum += an;  
        n++;
        anNext = n * n * pow(exp(1), -sqrt(n));
    } while (anNext > eps);
    cout.precision(10);
    cout << "result(do..while): " << sum << endl;
    //while
    n = 0, an = n * n * pow(exp(1), -sqrt(n)), sum = an;
    n = 1; anNext = n * n * pow(exp(1), -sqrt(n));
    while (anNext > eps) 
    {
        an = anNext;
        sum += an;
        n++;
        anNext = n * n * pow(exp(1), -sqrt(n));
    }
    cout << "result(while): " << sum << endl;
    //доп. задания
    //6.1.
    //Напишите программу, перемножающую целые числа без использования операции
    //«* ».Например, при умножении целых чисел n* m число m надо сложить само с
    //собой n раз(m + m + ... + m).
    cout << "Введите два целых числа" << endl;
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;
    int mult = 0;
    for (int i = 0; i < abs(num2); i++)
        mult += abs(num1);
    if ((num1 < 0 || num2 < 0) && !(num1 < 0 && num2 < 0)) mult = -mult;
    cout << num1 << " * " << num2 << " = " << mult << endl;

    return 0;
}
