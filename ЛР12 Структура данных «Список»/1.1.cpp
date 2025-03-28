#include <iostream>      
#include <stdio.h>
#include <windows.h>
#include "1.1.h"
using namespace std;

int menu();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int ch;

    cout << "Добро пожаловать!" << endl;
    while (1)
    {
        switch (menu())
        {
        case 1:
            cout << "\nВведите целое число: ";
            cin >> ch;
            while (cin.fail() || cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Ошибка ввода: вводимое значение должно быть целым числом. Повторный ввод: ";
                cin >> ch;
            }
            insert(ch);
            break;
        case 2: printList(); break;
        case 3:
            cout << "\nЧисло элементов в списке: " << countList() << endl << endl << endl;
            break;
        case 4:
            if (!isEmpty())
                findMax();
            else
                cout << "\nСписок пуст!" << endl << endl << endl;
            break;
        case 5:
            if (!isEmpty())
                findMin();
            else
                cout << "\nСписок пуст!" << endl << endl << endl;
            break;
        case 6:
            if (!isEmpty())
            {
                cout << "\nВведите число для удаления его дубликатов: ";
                cin >> ch;
                while (cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Ошибка ввода: вводимое значение должно быть целым числом. Повторный ввод: ";
                    cin >> ch;
                }
                deleteDuplicates(ch);
            }
            else
                cout << "\nСписок пуст!" << endl << endl << endl;
            break;
        case 7:
            if (!isEmpty())
            {
                cout << "\nВведите чило для удаления его вхождений: ";
                cin >> ch;
                while (cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Ошибка ввода: вводимое значение должно быть целым числом. Повторный ввод: ";
                    cin >> ch;
                }
                deleteAllOccurrences(ch);
            }
            else
                cout << "\nСписок пуст!" << endl << endl << endl;
            break;
        case 8: return 0;
        }
    }
}


//МЕНЮ
int menu()
{
    register int er;
    cout << "//=================================//\nВведите:\n";
    cout << "1- для добавления нового элемента в список\n";
    cout << "2- для вывода списка\n";
    cout << "3- для подсчета числа элементов в списке\n";
    cout << "4- для поиска максимального элемента в списке\n";
    cout << "5- для поиска минимального элемента в списке\n";
    cout << "6- для удаления всех повторений числа\n";
    cout << "7- для удаления всех вхождений числа\n";
    cout << "8- для выхода\n";
    cin >> er;
    while (er <= 0 || er > 8 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 8. Повторный ввод: ";
        cin >> er;
    }
    return er;
}