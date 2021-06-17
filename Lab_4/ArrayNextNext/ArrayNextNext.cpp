#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    //6.1.Дан одномерный массив, переставить в обратном порядке элементы массива,
    //расположенные между минимальным и максимальным элементами.
    const int DIM = 11;
    int vector[DIM];
    for (int i = 0; i < DIM; i++) 
    {
        vector[i] = rand() % 2 != 0 ? rand() % 100 : -rand() % 100;
    }
    cout << "Исходный массив: ";
    for (int i = 0; i < DIM; i++)
    {
        cout << " " << vector[i];
    }
    cout << endl;
    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < DIM; i++)
    {
        if (vector[i] < vector[minIndex]) minIndex = i;
        if (vector[i] > vector[maxIndex]) maxIndex = i;
    }
    int startIndex = maxIndex > minIndex ? minIndex + 1 : maxIndex + 1;
    int endIndex   = minIndex > maxIndex ? minIndex - 1 : maxIndex - 1;
    if (endIndex - startIndex > 0)
    {
        int middle = endIndex - (endIndex - startIndex) / 2;
        for (int i = startIndex; i < middle; i++)
        {
            int temp  = vector[i];
            vector[i] = vector[endIndex];
            vector[endIndex] = temp;
        }
        cout << "Перестановка выполнена" << endl;
    }
    else cout << "Перестановка не требуется" << endl;
    //OUTPUT
    cout << "Полученный массив: ";
    for (int i = 0; i < DIM; i++)
    {        
        cout << " " << vector[i];
    }
}
