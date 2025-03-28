/*����������� ������ �� ������  ��������� �� ������������ ������ 11(��� 8).
-  ������� ���������� ��������(� ���������� �������)
-  ������� �������� ��������
-  ����� ����� ������ �� �����
-  ����� �� ���������*/
#include <iostream>      
#include <stdio.h>                      
#include <string.h>
#include <iomanip>
#include <fstream>
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
	cout << "\n������� ������� ��������: ";
	cin >> mas.fam;
	cout << "������� ��� ��������: ";
	cin >> mas.im;
	cout << "������� �������� ��������: ";
	cin >> mas.otch;
	cout << "������� ��� �������� ��������: ";
	cin >> mas.bith;
	cout << "������� ��� ����������� � �����: ";
	cin >> mas.ya;
	cout << "������� ������ �� ������ �� ������ �������: ";
	cin >> mas.marks[0];
	while (mas.marks[0] <= 0 || mas.marks[0] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas.marks[0];
	}
	cout << "������� ������ �� ������ ���������� �� ������ �������: ";
	cin >> mas.marks[1];
	while (mas.marks[1] <= 0 || mas.marks[1] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas.marks[1];
	}
	cout << "������� ������ �� ����������� �� ������ �������: ";
	cin >> mas.marks[2];
	while (mas.marks[2] <= 0 || mas.marks[2] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas.marks[2];
	}
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
		cout << "\n������� " << mas.fam << " ����� ������� " << position << ".";
	}
	else
		cout << "\n" << mas.fam << " �� ��������. ������������ ������!";
}


//����� ������
void printList() {
	list* current = s;

	if (current == NULL)
		cout << "\n������ ����!" << endl << endl << endl;
	else
	{
		cout << "|===================================================������==================================================|\n";
		cout << "| " << setw(16) << "�������" << " | "
			<< setw(16) << "���" << " | "
			<< setw(16) << "��������" << " | "
			<< setw(16) << "��� ��������" << " | "
			<< setw(16) << "��� �����������" << " | "
			<< setw(10) << "������" << " |\n";
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

//��������
extern void del()
{
	char fd[20];
	cout << "\n������� ������� �������� ��� ��������: ";
	cin >> fd;
	list* current = s, * previous = NULL;

	while (current != NULL && strcmp(fd, current->data.fam) != 0)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "������ " << fd << " �� ������ � ������.";
		cout << "\n__________________________________" << endl << endl << endl;
		return;
	}

	if (previous == NULL)
		s = current->next;
	else
		previous->next = current->next;
	delete current;
	cout << "������� " << fd << " ������� ������!";
	cout << "\n__________________________________" << endl << endl << endl;
}
