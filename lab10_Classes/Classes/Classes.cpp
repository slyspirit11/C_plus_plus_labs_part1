﻿#include <iostream>
#include "Octal.h"
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     /*1. Каждый разрабатываемый класс должен, как правило, содержать следующие
элементы: скрытые поля, конструкторы с параметрами и без параметров, методы,
перегруженные операции. Функциональные элементы класса должны
обеспечивать непротиворечивый, полный, минимальный и удобный интерфейс
класса. При возникновении ошибок должны выбрасываться исключения.
----------------------------------------------------------------------------
Описать класс для работы с восьмеричным числом, хранящимся в виде строки
символов. Реализовать конструкторы, свойства, методы и следующие операции:
- операции присваивания, реализующие значимую семантику;
- операции сравнения;
- преобразование в десятичное число;
- форматный вывод;
- доступ к заданной цифре числа по индексу.*/
    char number[] = "126";
    Octal f(number);
    f.Print();
    cout << endl << "Цифр в числе: " << f.GetLength() << endl;
    Octal g("1117");
    g.Print();
    cout << endl << "Цифр в числе: " << g.GetLength() << endl;
    Octal p(f);
    p.Print();
    cout << endl << "--------------------------------------------" << endl;
    p.Print();
    cout << endl << "Decimal number: " << p.ToDecimal() << endl;
    cout << "Первая цифра восьмеричного числа: " << p[0] << endl;
    cout << "Вторая цифра восьмеричного числа: " << p[1] << endl;
    cout << "Третья цифра восьмеричного числа: " << p[2] << endl;
    p[2] = '7';
    cout << "Третья цифра восьмеричного числа: " << p[2] << endl;
    g = f = p;
    g.Print(); cout << endl;
    f.Print(); cout << endl;
    f.Assign("1005");
    g.Assign("1117");
    cout << "f >>> "; f.Print(); cout << endl;
    cout << "g >>> "; g.Print(); cout << endl;
    cout.setf(ios::boolalpha);
    cout << "f < g: " << (f < g) << " f <= g: " << (f <= g) << " f == g: " << (f == g) << endl
         << "f != g: " << (f != g) << " f > g: " << (f > g) << " f >= g: " << (f >= g) << endl;


}