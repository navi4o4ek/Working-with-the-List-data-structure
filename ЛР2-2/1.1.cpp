#include <iostream>      
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include "1.1.h"
using namespace std;

int menu();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Добро пожаловать!" << endl;
    while (1)
    {
        switch (menu())
        {
        case 1: enter_new(); break;
        case 2: fastEnter(); break;
        case 3: printList(); break;
        case 4: del(); break;
        case 5: return 0;
        }
    }
}


//МЕНЮ
int menu()
{
    register int er;
    cout << "//=================================//\nВведите:\n";
    cout << "1- для добавления новой записи в список\n";
    cout << "2- для быстрого добавления новой записи в список\n";
    cout << "3- для вывода списка\n";
    cout << "4- для удаления записи в списке\n";
    cout << "5- для выхода\n";
    cin >> er;
    while (er <= 0 || er > 5 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 4. Повторный ввод: ";
        cin >> er;
    }
    return er;
}
