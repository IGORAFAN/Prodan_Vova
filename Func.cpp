#pragma once
#include < iostream > 
#include < conio.h > 
#include < queue > 
#include "Header.h"
using namespace std;

queue < double > line;

void prewiev() {
	cout << "����� ����������!" << endl;
	cout << "��������� ������� ��� ������ � ��������!" << endl << endl;
}

double set_Data() {
	double temp;
	for (;;) {
		cout << "\n������� ������� � �������> ";
		cin >> temp;
		if (!cin) {
			cout << "�� ��������� ������� ������\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	return temp;
}

void set_1Element(double arg_elem) {
	line.emplace(arg_elem);
	cout << "������� �����!" << endl;
}

void set_Elements(double arg_elem) {
	line.emplace(arg_elem);
	cout << "������� �����!" << endl << endl;
	for (;;) {
		int temp;
		cout << "1 - ������ ��� �������" << endl;
		cout << "2 - ������!" << endl;
		cout << "����> ";
		cin >> temp;
		if (temp == 1) {

			set_Elements(set_Data());
		}
		else if (temp == 2) {

			system("cls");
			what_u_want();
		}
		else {
			cout << "\n�� ��������� ������� ������\n";
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
		cout << "������� �����!" << endl;
	}
}

void delete_All_Elem() {
	if (!line.empty()) {
		int j = line.size();
		for (int i = 0; i < j; i++) {
			line.pop();
			cout << "������� - " << i << " �����!" << endl;
		}
	}
}

void get_1Element() {
	if (!line.empty()) {
		cout << "������ ������� � ������� " << line.front() << endl;
	}
}

void get_Elements() {
	if (!line.empty()) {
		int j = line.size();
		for (int i(0); i < j; i++) {
			cout << "������� - " << i << " " << line.front() << endl;
			line.pop();
		}
	}
}
void what_u_want() {
	int variant;
	cout << "1 - ������ ������� � ����� �������" << endl;
	cout << "2 - ������ ��������� ��������� � ����� �������" << endl;
	cout << "3 - ������ ������ �������" << endl;
	cout << "4 - ������� ������ ������� �� �������" << endl;
	cout << "5 - ������� ��� �������� �� �������" << endl;
	cout << "6 - ����������� ������ ������� � �������" << endl;
	cout << "7 - ����������� ��� �������� � �������(����� ��������� ������� ������������)" << endl;
	cout << "����>";
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
		cout << "������ ������� - " << what_Size();
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
		cout << "�� ��������� ������� ������\n" << endl;
		break;
	}
}

void restart_program() {
	cout << "������������� ���������?" << endl;
	cout << "1 - ����������" << endl;
	cout << "0 - �������� ���������" << endl;
	int temp;
	cout << "����>";
	cin >> temp;
	if (temp < 0 || temp > 1) {
		cout << "����������� �������� �����! ��������� ����!\n";
		cout << "����>";
		cin >> temp;
	}
	if (temp < 0 || temp > 1) {
		cout << "����������� �������� �����! �������� ���������!";
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