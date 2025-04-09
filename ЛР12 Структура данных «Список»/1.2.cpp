/*Создать однонаправленный список для целых чисел в порядке возрастания.(Использовать пример 12.1)
Написать следующие функции для работы со списком:
- countList - подсчет числа элементов;
- findMax - поиск максимального элемента списка; 
- findMin - поиск минимального элемента списка; 
– Удалить все повторения числа
- Удалить все вхождения числа*/
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


//ДОБАВЛЕНИЕ ЭЛЕМЕНТА
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
        cout << "Вставленный элемент " << value << " занял позицию " << position << "." << endl << endl << endl;
    }
    else
        cout << value << " не вставлен. Недостаточно памяти!" << endl << endl << endl;
}


//ПЕЧАТЬ СПИСКА
extern void printList()
{
    list* current = s;
    if (current == NULL)
        cout<<"\nСписок пуст!"<< endl << endl << endl;
    else
    {
        cout << "\nСПИСОК:" << endl;
        while (current != NULL)
        {
            cout << current->value << endl;
            current = current->next;
        }
        cout << "NULL" << endl << endl << endl;
    }
}


//ПРОВЕРКА НА ПУСТОТУ
extern int isEmpty()
{
    return s == NULL;
}


//ЧИСЛО ЭЛЕМЕНТОВ
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


//ПОИСК МАКСИМАЛЬНОГО
extern void findMax()
{
    list* current = s;
    register int position = 1;


    while (current->next != NULL)
    {
        current = current->next;
        position++;
    }

    cout << "\nМаксимальный элемент " << current->value << " найден на позиции " << position << "." << endl << endl << endl;
}


//ПОИСК МИНИМАЛЬНОГО
extern void findMin()
{
    cout << "\nМинимальный элемент " << s->value << " найден на позиции 1" << "." << endl << endl << endl;
}


//УДАЛИТЬ ДУБЛИКАТЫ
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
    cout << "Все дубликаты " << value << " успешно удалены!" << endl << endl << endl;
}


//УДАЛИТЬ ВХОЖДЕНИЯ
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
    cout << "Все вхождения " << value << " успешно удалены!" << endl << endl << endl;
}