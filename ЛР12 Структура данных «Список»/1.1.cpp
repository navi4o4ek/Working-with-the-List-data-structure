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

    cout << "����� ����������!" << endl;
    while (1)
    {
        switch (menu())
        {
        case 1:
            cout << "\n������� ����� �����: ";
            cin >> ch;
            while (cin.fail() || cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "������ �����: �������� �������� ������ ���� ����� ������. ��������� ����: ";
                cin >> ch;
            }
            insert(ch);
            break;
        case 2: printList(); break;
        case 3:
            cout << "\n����� ��������� � ������: " << countList() << endl << endl << endl;
            break;
        case 4:
            if (!isEmpty())
                findMax();
            else
                cout << "\n������ ����!" << endl << endl << endl;
            break;
        case 5:
            if (!isEmpty())
                findMin();
            else
                cout << "\n������ ����!" << endl << endl << endl;
            break;
        case 6:
            if (!isEmpty())
            {
                cout << "\n������� ����� ��� �������� ��� ����������: ";
                cin >> ch;
                while (cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "������ �����: �������� �������� ������ ���� ����� ������. ��������� ����: ";
                    cin >> ch;
                }
                deleteDuplicates(ch);
            }
            else
                cout << "\n������ ����!" << endl << endl << endl;
            break;
        case 7:
            if (!isEmpty())
            {
                cout << "\n������� ���� ��� �������� ��� ���������: ";
                cin >> ch;
                while (cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "������ �����: �������� �������� ������ ���� ����� ������. ��������� ����: ";
                    cin >> ch;
                }
                deleteAllOccurrences(ch);
            }
            else
                cout << "\n������ ����!" << endl << endl << endl;
            break;
        case 8: return 0;
        }
    }
}


//����
int menu()
{
    register int er;
    cout << "//=================================//\n�������:\n";
    cout << "1- ��� ���������� ������ �������� � ������\n";
    cout << "2- ��� ������ ������\n";
    cout << "3- ��� �������� ����� ��������� � ������\n";
    cout << "4- ��� ������ ������������� �������� � ������\n";
    cout << "5- ��� ������ ������������ �������� � ������\n";
    cout << "6- ��� �������� ���� ���������� �����\n";
    cout << "7- ��� �������� ���� ��������� �����\n";
    cout << "8- ��� ������\n";
    cin >> er;
    while (er <= 0 || er > 8 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 8. ��������� ����: ";
        cin >> er;
    }
    return er;
}