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

    cout << "����� ����������!" << endl;
    while (1)
    {
        switch (menu())
        {
        case 1: enter_new(); break;
        case 2: printList(); break;
        case 3: del(); break;
        case 4: return 0;
        }
    }
}


//����
int menu()
{
    register int er;
    cout << "//=================================//\n�������:\n";
    cout << "1- ��� ���������� ����� ������ � ������\n";
    cout << "2- ��� ������ ������\n";
    cout << "3- ��� �������� ������ � ������\n";
    cout << "4- ��� ������\n";
    cin >> er;
    while (er <= 0 || er > 4 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 4. ��������� ����: ";
        cin >> er;
    }
    return er;
}
