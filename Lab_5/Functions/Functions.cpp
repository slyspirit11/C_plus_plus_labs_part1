#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;
void HighlightConsoleText(const char* text, const char* color ="32");
void ShowArray(int*, int);
void ShowArray(double*, int);
const int DIM = 5;
void ShowMatrix(double [DIM][DIM]);
double* GetGeometricMeansByColumns(double matrix[DIM][DIM]);
double g(double, double);
double g(double*, double*);
int Max(int*, const int&);
int Max(int*, const int*);
int Product(int*, const int&);
int Product(int*, const int*);
double ComputeSum(double eps, int n = 0);
double ComputeSum(const double* eps, int n = 0);

int main()
{
	setlocale(LC_ALL, "Russian");
	//задание 5.1.
	//Даны действительные числа s,t. Получить g(1.2,s) + g(t,s) - g(2s-1,st), где
	//g(a,b) = (a^2-b^2)/(2ab-a-b) + (a+b)*sqrt(abs(a+b)/2)
	HighlightConsoleText("Задание 5.1.");
	double s = 0.0, t = 0.0;
	cout << "Введите s: " << endl;	cin >> s;
	cout << "Введите t: " << endl;	cin >> t;
	double result = g(1.2, s) + g(t, s) - g(2 * s - 1, s * t);
	cout << "Результат вычисления: " << result << endl;
	//Задание 5.2. Передача массивов в функцию(одномерные массивы)
	//Дан одномерный массив, состоящий из N целочисленных элементов.
	//5.2.1.Найти максимальный положительный элемент.
	//5.2.2.Вычислить произведение элементов массива.
	HighlightConsoleText("Задание 5.2.");
	srand(static_cast<unsigned int>(time(0)));
	const int N = 10;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 2 ? rand() % 100 : -rand() % -100;
	}
	cout << "Исходный массив: " << endl;
	ShowArray(arr, N); cout << endl;
	//Найти максимальный положительный элемент
	int max = Max(arr, &N);
	max = Max(arr, N);
	max ?
		cout << "Максимальный положительный элемент массива: " << max << endl :
		cout << "В массиве нет положительных элементов" << endl;
	//Вычислить произведение элементов массива
	int product = Product(arr, &N);
	product = Product(arr, N);
	cout << "Произведение элементов массива равно: " << product << endl;
	//Задание 5.3. Передача массивов в функцию(многомерные массивы)
	/*Дана матрица A(5,5). Сформировать одномерный массив C(5) из
	среднегеометрических значений положительных элементов каждого столбца
	матрицы.*/
	HighlightConsoleText("Задание 5.3.");
	double matrix[DIM][DIM] = {};
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			matrix[i][j] = rand() % 2 ? rand() % 100 : -rand() % 100;
		}
	}
	cout << "Исходная матрица: " << endl;
	ShowMatrix(matrix);
	double* geometricMeans = GetGeometricMeansByColumns(matrix);
	cout << "Среднегеометрические значения положительных элементов каждого столбца: " << endl;
	ShowArray(geometricMeans, DIM);
	cout << endl;
	//Задание 5.4. Использование рекурсии
	//Найти сумму ряда с точностью eps, общий член которого равен an = (n^2)*e^(-sqrt(n)).
	//Точность считается достигнутой, если следующий член последовательности меньше заданного eps.
	HighlightConsoleText("Задание 5.4.");
	const double EPS = 1e-5;
	double sum = ComputeSum(EPS);
	sum = ComputeSum(&EPS);
	cout << "Точность: " << EPS << endl;
	cout.precision(8);
	cout << "Вычисленная сумма ряда: " << sum << endl;

}
double g(double a, double b)
{
	if(2 * a * b - a - b) 
		return (a * a - b * b) / (2 * a * b - a - b) + (a + b) * sqrt(abs(a + b) / 2);
	else { cout << "Ошибка: деление на ноль" << endl; return 0.0; }
}
double g(double* p_a, double* p_b)
{
	double a = *p_a; double b = *p_b;
	if (2 * a * b - a - b)
		return (a * a - b * b) / (2 * a * b - a - b) + (a + b) * sqrt(abs(a + b) / 2);
	else { cout << "Ошибка: деление на ноль" << endl; return 0.0; }
}
void HighlightConsoleText(const char* text, const char* color)
{
	cout << "\x1b[" << color << "m" << text << "\x1b[0m" << endl;
}
void ShowArray(int* arr, int N) 
{
	for (int i = 0; i < N; i++)
	{
		cout << *(arr + i) << " ";
	}
}
void ShowArray(double* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << *(arr + i) << " ";
	}
}
void ShowMatrix(double matrix[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//Метод возвращает максимальное положительное число в целочисленном массиве.
//Если положительные элементы отсутствуют - возвращается 0.
int Max(int* arr, const int & N)
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (*(arr + i) > max) max = *(arr + i);
	}
	return max;
}
int Max(int* arr, const int* N)
{
	int max = 0;
	for (int i = 0; i < *N; i++)
	{
		if (*(arr + i) > max) max = *(arr + i);
	}
	return max;
}
//Метод возвращает произведение всех элементов целочисленного массива.
int Product(int* arr, const int& N)
{
	int product = 1;
	for (int i = 0; i < N; i++)
	{
		product *= *(arr + i);
	}
	return product;
}
int Product(int* arr, const int* N)
{
	int product = 1;
	for (int i = 0; i < *N; i++)
	{
		product *= *(arr + i);
	}
	return product;
}

//Метод возвращает массив среднегеометрических значений положительных элементов столбцов матрицы.
//Для столбцов без положительных элементов значение будет равно 0
double* GetGeometricMeansByColumns(double matrix[DIM][DIM])
{
	double* geometricMeans = new double[DIM];
	for (int j = 0; j < DIM; j++)
	{
		double product = 1.0; int posCount = 0;
		for (int i = 0; i < DIM; i++)
		{
			if (matrix[i][j] > 0)
			{
				product *= matrix[i][j];
				posCount++;
			}
		}
		geometricMeans[j] = posCount ? pow(product, 1.0 / posCount) : 0;
	}
	return geometricMeans;
}
double ComputeSum(double eps, int n)
{
	if ((n + 1) * (n + 1) * exp(-sqrt(n + 1)) < eps) return n * n * exp(-sqrt(n));
	else return n * n * exp(-sqrt(n)) + ComputeSum(eps, ++n);
}
double ComputeSum(const double* eps, int n)
{
	if ((n + 1) * (n + 1) * exp(-sqrt(n + 1)) < *eps) return n * n * exp(-sqrt(n));
	else return n * n * exp(-sqrt(n)) + ComputeSum(eps, ++n);
}