/*Реализовать список на основе  структуры из лабораторной работы 11(или 8).
-  функции добавления элемента(в алфавитном порядке)
-  функция удаления элемента
-  вывод всего списка на экран
-  выход из программы*/
#include <iostream>                           
#include <string.h>
#include <iomanip>
#include <windows.h>
#include "1.1.h"
#define path "dataBase.txt"
using namespace std;

struct student {
	char fam[20], im[20], otch[20];
	int bith;
	int ya;
	int marks[3];
};

static student mas;

struct list {
	student data;      
	list* next;        
};

static list* s = NULL;

extern void enter_new()
{
	cout << "\nВведите фамилию студента: ";
	cin >> mas.fam;
	cout << "Введите имя студента: ";
	cin >> mas.im;
	cout << "Введите отчество студента: ";
	cin >> mas.otch;
	cout << "Введите год рождения студента: ";
	cin >> mas.bith;
	cout << "Введите год поступления в БГУИР: ";
	cin >> mas.ya;
	cout << "Введите оценку по физике за первый семестр: ";
	cin >> mas.marks[0];
	while (mas.marks[0] <= 0 || mas.marks[0] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas.marks[0];
	}
	cout << "Введите оценку по высшей математике за первый семестр: ";
	cin >> mas.marks[1];
	while (mas.marks[1] <= 0 || mas.marks[1] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas.marks[1];
	}
	cout << "Введите оценку по информатике за первый семестр: ";
	cin >> mas.marks[2];
	while (mas.marks[2] <= 0 || mas.marks[2] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas.marks[2];
	}
	insert();
	cout << "\n__________________________________" << endl << endl << endl;
	
}


extern void fastEnter()
{
	cout << "\nВведите фамилию, имя, отчество, год рождения, год поступления и три отметки за первый семестр по физике, высшей математике и информатике:" << endl;
	cin >> mas.fam >> mas.im >> mas.otch >> mas.bith >> mas.ya >> mas.marks[0] >> mas.marks[1] >> mas.marks[2];
	insert();
	cout << "\n__________________________________" << endl << endl << endl;
}

extern void insert()
{
	list* newP = new list, * previous, * current;

	if (newP != NULL)
	{
		newP->data = mas;
		newP->next = NULL;
		previous = NULL;
		current = s;
		register int position = 1;
		while (current != NULL && strcmp(mas.fam, current->data.fam) > 0)
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
		cout << "\nСтудент " << mas.fam << " занял позицию " << position << ".";
	}
	else
		cout << "\n" << mas.fam << " не вставлен. Недостаточно памяти!";
}


//ВЫВОД СПИСКА
void printList() {
	list* current = s;

	if (current == NULL)
		cout << "\nСписок пуст!" << endl << endl << endl;
	else
	{
		cout << "|===================================================СПИСОК==================================================|\n";
		cout << "| " << setw(16) << "Фамилия" << " | "
			<< setw(16) << "Имя" << " | "
			<< setw(16) << "Отчество" << " | "
			<< setw(16) << "Год рождения" << " | "
			<< setw(16) << "Год поступления" << " | "
			<< setw(10) << "Оценки" << " |\n";
		cout << "|===========================================================================================================|\n";

		while (current != NULL)
		{
			cout << "| " << setw(16) << current->data.fam << " | "
				<< setw(16) << current->data.im << " | "
				<< setw(16) << current->data.otch << " | "
				<< setw(16) << current->data.bith << " | "
				<< setw(16) << current->data.ya << " | "
				<< setw(2) << current->data.marks[0] << ", "
				<< setw(2) << current->data.marks[1] << ", "
				<< setw(2) << current->data.marks[2] << " |\n";

			current = current->next;
		}
		cout << "|===========================================================================================================|" << endl << endl << endl;
	}
}

//УДАЛЕНИЕ
extern void del()
{
	char fd[20];
	cout << "\nВведите фамилию студента для удаления: ";
	cin >> fd;
	list* current = s, * previous = NULL;

	while (current != NULL && strcmp(fd, current->data.fam) != 0)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "Стдент " << fd << " не найден в списке.";
		cout << "\n__________________________________" << endl << endl << endl;
		return;
	}

	if (previous == NULL)
		s = current->next;
	else
		previous->next = current->next;
	delete current;
	cout << "Студент " << fd << " успешно удален!";
	cout << "\n__________________________________" << endl << endl << endl;
}



//Жернов Герман Андреевич 2002 2019 9 8 10
//Сидоров Дмитрий Викторович 2003 2020 9 10 10
//Попов Иван Анатольевич 2004 2021 7 7 8
//Шишкевич Анна Сергеевна 2004 2022 7 6 8
//Иванова Ксения Викторовна 2004 2022 5 8 7
//Кузнецова Екатерина Павловна 2004 2022 5 6 8
//Предметов Абдул Каримов 1994 2023 4 5 6
//Смирнова Ольга Николаевна 2005 2023 4 8 5
//Булат Александр Петрович 2006 2023 10 6 9
//Петров Максим Александрович 2000 2024 6 7 9
//Ткаченко Александр Васильевич 2006 2024 9 9 9
//Соколов Артем Сергеевич 2007 2024 7 10 10