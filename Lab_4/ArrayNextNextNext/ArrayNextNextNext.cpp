#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
/*В каждой строке заданного двумерного массива размерности n x m сменить
  знак максимального по модулю элемента на противоположный.*/
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	const int N = 10, M = 5;
	int matrix[N][M];
	cout << "Исходный двумерный массив: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = rand() % 2 ? rand() % 100 : -rand() % 100;
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//в каждой строке массива максимальный по модулю элемент изменяется на противоположный
	for (int i = 0; i < N; i++)
	{
		int maxIndex = 0;
		for (int j = 0; j < M; j++)
		{
			if (abs(matrix[i][j]) > abs(matrix[i][maxIndex])) maxIndex = j;
		}
		matrix[i][maxIndex] = -matrix[i][maxIndex];
	}
	cout << "Полученный двумерный массив: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}

}
