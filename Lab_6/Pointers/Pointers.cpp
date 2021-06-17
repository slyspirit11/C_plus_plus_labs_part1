#include <iostream>
using namespace std;
double GetSquareArea(double* side);
void GetTriangleAngles(double&, double&, double&, double*& angles);
double* FillDynamicArray(int M);
double Max(double* arr, int size);
bool GetArithmeticMean(double* arr, int size, double& mean);
void PrintReversed(double* arr, int size);
double F1(double x);
double F2(double x);
bool F3(double x, double& result);
bool F4(double x, double& result);

int main()
{
    setlocale(LC_ALL, "Russian");
    //5.1. Указатели. 
    //Вычислить площадь квадрата
    double side = 5;
    double area = GetSquareArea(&side);
    cout << "Площадь квадрата равна " << area << endl;
    //5.2. Ссылки
    //Вычислить углы треугольника, зная его стороны.
    cout << "Углы треугольника: " << endl;
    double a = 10, b = 12, c = 5;
    const int N = 3;
    double angles[N] = {};
    double* ref_angles = &(*angles);
    GetTriangleAngles(a, b, c, ref_angles);
    for (int i = 0; i < N; i++) cout << angles[i] << " ";
    cout << endl;
    //5.3. Динамические массива. Имя массива как указатель.
    //Дан одномерный массив, состоящий из N вещественных элементов.
    //    5.3.1.Ввести массив с клавиатуры.
    //    5.3.2.Найти максимальный элемент.
    //    5.3.3.Вычислить среднеарифметическое отрицательных элементов массива.
    //    5.3.4.Вывести массив на экран в обратном порядке.
    //5.3.1.Ввести массив с клавиатуры
    int size = 0;
    cout << "Введите размер массива: "; cin >> size; cout << endl;
    double* arr = FillDynamicArray(size);
    cout << "Заполненный массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << *(i + arr) << " ";
    }
    cout << endl;
    //5.3.2.Найти максимальный элемент.
    double max = Max(arr, size);
    cout << "Максимльный элемент массива: " << max << endl;
    //5.3.3.Вычислить среднеарифметическое отрицательных элементов массива.
    double mean = 0;
    GetArithmeticMean(arr, size, mean) ?
        cout << "Среднее арифметическое отрицательных элементов массива: " << mean :
        cout << "Отрицательные элементы в массиве отсутствуют";
    cout << endl;    
    //5.3.4.Вывести массив на экран в обратном порядке.
    cout << "Элементы массива в обратном порядке: "; PrintReversed(arr, size); cout << endl;
    delete[] arr;
    //5.4. Указатели на функцию
    //Предоставить пользователю выбор функции. При невозможности вычислить значении функции в выбранной точке x
    //выдать соответствующее сообщение.
    //5.4.1. x^3-3x-2exp(-x)
    //5.4.2. 1/(3-cosx)
    //5.4.3. (log(x, 3))^2
    //5.4.4. 1/(1-x)
    int choice = 0;
    double x = 0.0, result = 0;
    cout << "1. x^3-3x-2exp(-x)\n" << "2. 1/(3-cosx)\n" << "3. (log(x, 3))^2\n" << "4. 1 / (1 - x)\n";
    cout << "Выберите функцию: "; cin >> choice;
    cout << "Введите x: "; cin >> x;
    cout << "Результат: ";
    switch (choice)
    {
    case 1: 
        double (*pF1) (double);
        pF1 = F1;
        cout << (*pF1)(x) << endl; break;
    case 2:
        double (*pF2) (double);
        pF2 = F2;
        cout << (*pF2)(x) << endl; break;
    case 3:
        bool (*pF3) (double, double&);
        pF3 = F3;
        (*pF3)(x, result) ?
            cout << result << endl :
            cout << "В выбранной точке x вычисление функции невозможно";
        break;
    case 4:
        bool (*pF4) (double, double&);
        pF4 = F4;
        (*pF4)(x, result) ?
            cout << result << endl :
            cout << "В выбранной точке x вычисление функции невозможно";
        break;
    }

}
//Метод вычисляет площать квадрата
double GetSquareArea(double* side)
{
    return *side * *side;
}
//Метод находит углы треугольника по его сторонам
void GetTriangleAngles(double& a, double& b, double& c, double*& angles)
{
    //ab
    angles[0] = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / (22.0 / 7);
    //bc
    angles[1] = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / (22.0 / 7);
    //ca
    angles[2] = acos((c * c + a * a - b * b) / (2 * c * a)) * 180.0 / (22.0 / 7);
}
//В методе заполняется динамический массив
double* FillDynamicArray(int size)
{
    double* arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Введите arr[" << i << "]: ";
        cin >> *(arr + i); cout << endl;
    }
    return arr;
}
//Метод возвращает максимальный элемент массива
double Max(double* arr, int size)
{
    double max = *arr;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) > max) max = *(arr + i);
    }
    return max;
}
//Метод находит среднее арифметическое торицательных элементов массива
bool GetArithmeticMean(double* arr, int size, double& mean)
{
    int negCount = 0;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) < 0) 
        {
            sum += *(arr + i);
            negCount++;
        }
    }
    if (negCount)
    {
        mean = sum / negCount; return true;
    }
    else return false;
}
//Метод печатает массив в обратном порядке
void PrintReversed(double* arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << *(arr + i) << " ";
    }
}
//Функции
double F1(double x)
{
    return x * x * x - 3 * x - 2 * exp(-x);
}
double F2(double x)
{
    return 1 / (3 - cos(x));
}
bool F3(double x, double& result)
{
    if (x > 0)
    {
        result = (log(x) / log(3)) * (log(x) / log(3)); return true;
    }
    else return false;
}
bool F4(double x, double& result)
{
    if (x != 1)
    {
        return 1 / (1 - x);
    }
    else return false;
    
}
