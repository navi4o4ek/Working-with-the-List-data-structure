/*������� ���������������� ������ ��� ����� ����� � ������� �����������.(������������ ������ 12.1)
�������� ��������� ������� ��� ������ �� �������:
- countList - ������� ����� ���������;
- findMax - ����� ������������� �������� ������; 
- findMin - ����� ������������ �������� ������; 
� ������� ��� ���������� �����
- ������� ��� ��������� �����*/
#include <iostream>      
#include <stdio.h>
#include <windows.h>
#include "1.1.h"
using namespace std;

struct list
{
    int value;
    struct list* next;
};

static list* s = NULL;


//���������� ��������
extern void insert(int value)
{
    list* newP = new list, * previous, * current;
    if (newP != NULL)
    {
        newP->value = value;
        newP->next = NULL;
        previous = NULL;
        current = s;
        register int position = 1;

        while (current != NULL && value > current->value)
        {
            previous = current;
            current = current->next;
            position++;
        }

        if (previous == NULL)
        {
            newP->next = s;
            s = newP;
        }
        else
        {
            previous->next = newP;
            newP->next = current;
        }
        cout << "����������� ������� " << value << " ����� ������� " << position << "." << endl << endl << endl;
    }
    else
        cout << value << " �� ��������. ������������ ������!" << endl << endl << endl;
}


//������ ������
extern void printList()
{
    list* current = s;
    if (current == NULL)
        cout<<"\n������ ����!"<< endl << endl << endl;
    else
    {
        cout << "\n������:" << endl;
        while (current != NULL)
        {
            cout << current->value << endl;
            current = current->next;
        }
        cout << "NULL" << endl << endl << endl;
    }
}


//�������� �� �������
extern int isEmpty()
{
    return s == NULL;
}


//����� ���������
extern int countList()
{
    register int count = 0;
    list* current = s;
    
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}


//����� �������������
extern void findMax()
{
    list* current = s;
    register int position = 1;


    while (current->next != NULL)
    {
        current = current->next;
        position++;
    }

    cout << "\n������������ ������� " << current->value << " ������ �� ������� " << position << "." << endl << endl << endl;
}


//����� ������������
extern void findMin()
{
    cout << "\n����������� ������� " << s->value << " ������ �� ������� 1" << "." << endl << endl << endl;
}


//������� ���������
extern void deleteDuplicates(int value)
{
    list* current = s, * previous = NULL, * temp;
    bool f = false;

    while (current != NULL)
    {
        if (current->value == value)
        {
            if (!f)
            {
                f = true;
                previous = current;
                current = current->next;
            }
            else
            {
                temp = current;
                previous->next = current->next;
                current = current->next;
                delete temp;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    cout << "��� ��������� " << value << " ������� �������!" << endl << endl << endl;
}


//������� ���������
extern void deleteAllOccurrences(int value)
{
    list* current = s, * previous = NULL, * temp;

    while (current != NULL)
    {
        if (current->value == value)
        {
            temp = current;
            if (previous == NULL)
                s = current->next;
            else
                previous->next = current->next;
            current = current->next;
            delete temp;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    cout << "��� ��������� " << value << " ������� �������!" << endl << endl << endl;
}