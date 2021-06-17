#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //6.2.
    /*Создайте программу, играющую с пользователем в орлянку. Программа должна
спрашивать у пользователя орел или решка. Если пользователь вводит 0, то
выбирает орла, 1 – решку, любое другое число – конец игры. Программа должна
вести учет выигрышей и проигрышей и после каждого раунда сообщать
пользователю о состоянии его счета. Пусть вначале на счету 1 рубль и ставка в
каждом коне тоже 1 рубль. Если денег у пользователя не осталось игра
прекращается.*/
    srand(static_cast<unsigned int>(time(0)));
    int rubbles = 1, choice = 0, rounds = 0;
    bool playing = true;
    cout << "Ваш счёт: " << rubbles << endl;
    cout << "Орёл == 0  Решка == 1" << endl;
    while (rubbles > 0 && playing)
    {
        rounds++;
        cout << "Раунд " << rounds << endl;
        cout << "Орёл или решка?" << endl;
        int rightChoice = rand() % 2;
        cout << "Что выпадет: " << rightChoice << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: case 1:
            if (choice == rightChoice)
            {
                cout << "Вы выиграли 1 рубль" << endl;
                rubbles++;
            }
            else
            {
                cout << "Вы проиграли 1 рубль" << endl;
                rubbles--;
            }
            break;
        default: playing = false; break;
        }
        cout << "Ваш счёт в рублях: " << rubbles << endl;
    }
    cout << "Игра завершена" << endl;


    return 0;
}

