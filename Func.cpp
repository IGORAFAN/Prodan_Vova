#pragma once
#include < iostream > 
#include < conio.h > 
#include < queue > 
#include "Header.h"
using namespace std;

queue < double > line;

void prewiev() {
	cout << "Добро пожаловать!" << endl;
	cout << "Программа создана для роботы с очередью!" << endl << endl;
}

double set_Data() {
	double temp;
	for (;;) {
		cout << "\nВведите елемент в очередь> ";
		cin >> temp;
		if (!cin) {
			cout << "Не корректно введены данные\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return temp;
}

void set_1Element(double arg_elem) {
	line.emplace(arg_elem);
	cout << "Елемент введён!" << endl;
}

void set_Elements(double arg_elem) {
	line.emplace(arg_elem);
	cout << "Елемент введён!" << endl << endl;
	for (;;) {
		int temp;
		cout << "1 - Ввести ещё элемент" << endl;
		cout << "2 - Хватит!" << endl;
		cout << "Ввод> ";
		cin >> temp;
		if (temp == 1) {

			set_Elements(set_Data());
		}
		else if (temp == 2) {

			system("cls");
			what_u_want();
		}
		else {
			cout << "\nНе корректно введены данные\n";
		}
	}
}

int what_Size() {
	if (!line.empty())
		return line.size();
	else
		return NULL;
}

void delete_1Elem() {
	if (!line.empty()) {
		line.pop();
		cout << "Елемент Удалён!" << endl;
	}
}

void delete_All_Elem() {
	if (!line.empty()) {
		int j = line.size();
		for (int i = 0; i < j; i++) {
			line.pop();
			cout << "Елемент - " << i << " Удалён!" << endl;
		}
	}
}

void get_1Element() {
	if (!line.empty()) {
		cout << "Первый элемент в очереди " << line.front() << endl;
	}
}

void get_Elements() {
	if (!line.empty()) {
		int j = line.size();
		for (int i(0); i < j; i++) {
			cout << "Елемент - " << i << " " << line.front() << endl;
			line.pop();
		}
	}
}
void what_u_want() {
	int variant;
	cout << "1 - Ввести елемент в конец очереди" << endl;
	cout << "2 - Ввести множество элементов в конец очереди" << endl;
	cout << "3 - Узнать размер очереди" << endl;
	cout << "4 - Удалить первый элемент из очереди" << endl;
	cout << "5 - Удалить все элементи из очереди" << endl;
	cout << "6 - Просмотреть первый элемент в очереди" << endl;
	cout << "7 - Просмотреть все елементы в очереди(после просмотра очередь опустошается)" << endl;
	cout << "Ввод>";
	cin >> variant;
	switch (variant) {
	case 1:
		set_1Element(set_Data());
		_getch();
		system("cls");
		what_u_want();
		break;
	case 2:
		set_Elements(set_Data());
		_getch();
		system("cls");
		what_u_want();
		break;
	case 3:
		cout << "Размер очереди - " << what_Size();
		_getch();
		system("cls");
		what_u_want();
		break;
	case 4:
		delete_1Elem();
		_getch();
		system("cls");
		what_u_want();
		break;
	case 5:
		delete_All_Elem();
		_getch();
		system("cls");
		what_u_want();
		break;
	case 6:
		get_1Element();
		_getch();
		system("cls");
		what_u_want();
		break;
	case 7:
		get_Elements();
		_getch();
		system("cls");
		what_u_want();
		break;
	default:
		cout << "Не корректно введены данные\n" << endl;
		break;
	}
}

void restart_program() {
	cout << "Перезапустить программу?" << endl;
	cout << "1 - Перезапуск" << endl;
	cout << "0 - Закрытие программы" << endl;
	int temp;
	cout << "Ввод>";
	cin >> temp;
	if (temp < 0 || temp > 1) {
		cout << "Неправильно Введенно число! Повторите Ввод!\n";
		cout << "Ввод>";
		cin >> temp;
	}
	if (temp < 0 || temp > 1) {
		cout << "Неправильно Введенно число! Закрытие программы!";
		_getch();
		exit(0);
	}
	else if (temp == 1) {
		system("cls");
		what_u_want();
		restart_program();
	}
	else exit(0);
}