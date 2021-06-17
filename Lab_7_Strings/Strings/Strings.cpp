#include <iostream>
#include <string>
#include <ctype.h>
/*1. Написать программу в соответствии с вариантом задания из пункта 5. Для первых
     двух заданий использовать для работы со строками массив типа char. Для
     последних двух заданий для работы со строками использовать тип string.
     2. Отладить и протестировать программы.*/
//   5 вариант 5,15,25,35 задание.
using namespace std;
void AddSpaces(char*, int, int);
void SwapWords(char*);
string ChangeCommasToDots(string);
string GetLongestSymmetricWord(string);
bool IsPalyndrome(string s);
int main()
{
    setlocale(LC_ALL, "Russian");
    /*5.5) В строку S добавить необходимое количество пробелов так, чтобы ее длина стала равна
    n. Причем: перед первым словом пробелы не добавлять, после последнего слова все
    пробелы удалить, добавленные пробелы равномерно распределить между словами.
    Если длина S превосходит n, удалить S из все слова, которые не укладываются в первые
    n символов, а оставшуюся часть преобразовать по вышеуказанным правилам.*/
    int offset = 1;//offset - запасная длина массива для проверки переполненности
    int len = 0;
    cout << "Введите длину строки: " << endl;
    cin >> len; 
    len += 1 + offset; //1 прибявляется для хранения терминального символа
    cout << "Введите строку: " << endl;
    char* s = new char[len];
    cin.ignore();
    cin.sync(); // сбрасывается всё содержимое буфера
    cin.getline(s, len);
    cout << "Строка: " << s << endl;
    cout << "Длина строки: " <<strlen(s) << endl;
    AddSpaces(s, len, offset);
    cout << "Преобразованная строка: " << s << endl;
    cout << "Длина строки: " << strlen(s) << endl;
    delete[] s;
    //5.15) В строке переставить местами рядом стоящие слова.
    char st[] = "a b c d e f g";
    cout << "Исходная строка: " << st << endl;
    SwapWords(st);
    cout << "Преобразованная строка: " << st << endl;
    //5.25) В строке все запятые заменить точкой, и перед первым словом вставить слово STRING.
    string a = "a, b, c, d, e, f, g";
    cout << "Исходная строка: " << a << endl;
    string b = ChangeCommasToDots(a);
    b.insert(0, "STRING");
    cout << "Преобразованная строка: " << b << endl;
    //5.35) В строке найти самое длинное симметричное слово.
    string str = "шалаш уровень доход racecar самоанализ noon level энциклопедия";
    cout << str << endl;
    cout << "Самое длинное симметричное слово: " << GetLongestSymmetricWord(str) << endl;
}
//Метод дополняет строку s пробелами так чтобы её длина стала равна len символов.
void AddSpaces(char* s, int len, int offset)
{
    //Если символ за пределами заданной длины строки - это буква/цифра или пробел или знак пунктуации:
    //если знак пунктуации - он удаляется
    //если буква/цифра - в цикле удаляется последняя непрерывная последовательность букв, затем последовательность пробелов
    //если пробел - удаляется последовательность пробелов и знаки пунктуации(если есть)
    //offset1 - то что нужно отнять от длины для доступа к последнему нетерминальному символу строки.
    int offset1 = offset + 1;
    if (isalnum(s[len - offset1]) | ispunct(s[len - offset1]) | isspace(s[len - offset1]))
    {
        while (ispunct(s[len - offset1]))
        {
            s[len - offset1] = '\0';
        }
        while (isalnum(s[len - offset1]))
        {
            s[len - offset1] = '\0';
            offset1++;
        }
        while (isspace(s[len - offset1]) | ispunct(s[len - offset1]))
        {
            s[len - offset1] = '\0';
            offset1++;
        }
    }
    int sLen = len - offset - 1;//slen - необходимое кол-во символов в строке без \0
    int currLen = strlen(s);//offset1 - на данном этапе индекс последнего нетерминального символа
    int spacesToAdd = sLen - currLen;
    cout << "Необходимая длина: " << sLen << endl;
    cout << "Текущая длина: " << currLen << endl;
    cout << "Сколько пробелов добавлять: " << spacesToAdd << endl;
    if (spacesToAdd > 0)
    {
        int spacesCount = 0, i = 0;
        while (s[i] != '\0')
        {
            if (isspace(s[i])) spacesCount++;
            i++;
        }
        //считается сколько пробелов добавлять между словами
        int spacesToAddOnce = spacesToAdd / spacesCount;
        cout << "Сколько пробелов добавлять между двумя соседними словами: " << spacesToAddOnce << endl;
        //если равномерно распределить пробелы не удаётся - остаток пробелов добавляется между последними двумя словами
        int residue = spacesToAdd - spacesToAddOnce * spacesCount;
        cout << "Остаток пробелов: " << residue << endl;
        //Алгоритм добавления пробелов
        //1.в цикле ищется индекс первого пробела
        //2.начиная с конца строки все символы сдвигаются на величину spacesToAddOnce во вложенном цикле
        //3.пробелы в количестве spacesToAddOnce вставляются после индекса первого пробела
        //4.ищется индекс следующего пробела --> обратно к шагу 1
        //1+.если пробел последний: в шагах 2 и 3 используется величина spacesTAddOnce + residue
        i = 0;
        int gapsCount = 0; // gapsCount - текущий номер пропуска между словами
        while (s[i] != '\0')
        {
            if (isspace(s[i]))
            {
                gapsCount++;
                if (gapsCount != spacesCount)
                {
                    //сдвиг символов
                    for (int j = strlen(s); j > i; j--)
                    {
                        s[j + spacesToAddOnce] = s[j];
                    }
                    //вставка пробелов
                    for (int k = i + 1; k <= i + spacesToAddOnce; k++)
                    {
                        s[k] = ' ';
                    }
                    i += spacesToAddOnce;
                }
                else
                {
                    //сдвиг символов
                    for (int j = strlen(s); j > i; j--)
                    {
                        s[j + spacesToAddOnce + residue] = s[j];
                    }
                    //вставка пробелов
                    for (int k = i + 1; k <= i + spacesToAddOnce + residue; k++)
                    {
                        s[k] = ' ';
                    }
                    i += spacesToAddOnce + residue;
                }
            }
            i++;
        }
    }
}
//Метод переставляет слова в строке следующим образом: 1 <> 2, 3 <> 4, ....
void SwapWords(char* s)
{
    char* sCopy = new char[strlen(s) + 1];
    strcpy(sCopy, s);
    char *word1, *word2;
    char* rest = sCopy;
    word1 = strtok_s(sCopy, " ", &rest);
    word2 = strtok_s(NULL, " ", &rest);
    //перестановка слов проводится только если слов несколько
    if (word2 != NULL)
    {
        bool isFirstWord = true;
        int i = 0, sIndex = 0;
        while (word1 != NULL)
        {
            if (word2 != NULL)
            {
                if (!isFirstWord) { s[sIndex] = ' '; sIndex++; }
                isFirstWord = false;
                while (word2[i] != '\0')
                {
                    s[sIndex] = word2[i];
                    sIndex++;
                    i++;
                }
                s[sIndex] = ' ';
                i = 0;
            }
            if (word1 != NULL)
            {
                while (word1[i] != '\0')
                {
                    sIndex++;
                    s[sIndex] = word1[i];
                    i++;
                }
                i = 0;
            }
            word1 = strtok_s(NULL, " ", &rest);
            word2 = strtok_s(NULL, " ", &rest);
            sIndex++;
        }
    }
    delete[] sCopy;
}
//Метод заменят все запятые в строке на точки
string ChangeCommasToDots(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] == ',') s[i] = '.';
    return s;
}
//Метод находит в строке самое длинное симметричное слово
string GetLongestSymmetricWord(string s)
{
    string longestSymWord, word;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            word += s[i];
        }
        else
        {
            if (!word.empty())
            {
                if (IsPalyndrome(word) & (word.length() > longestSymWord.length()))
                {
                    longestSymWord = word;
                }
                word.clear();
            }
        }
    }
    return longestSymWord;
}
//Метод проверяет слово на симметричность
bool IsPalyndrome(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - 1 - i]) return false;
    return true;
}