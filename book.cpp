#include<iostream>
#include<stdlib.h>
#include <fstream>

using namespace std;

string sitename[51];
string number[50];
string email[50];
string password[50];
int k = -1;

int checksite(string check) {
	for (int i = 0; i <= k; i++) {
		if (sitename[i] == check) {
			return 0;
		}
	}
	return 1;
}

void add() {
	string check = "";
	cout << "������� ����: ";
	cin >> check;
	
	if (checksite(check) == 1) {
		k++;
		sitename[k] = check;
	}
	else {
		cout << endl << "�� ��� ������� ������ � ����� �����" << endl;
		return;
	}
	cout << "������� ����� ��������: ";
	cin >> number[k];
	cout << "������� �����: ";
	cin >> email[k];
	cout << "������� ������: ";
	cin >> password[k];
}
void print(int c) {
	if (sitename[c] == "")
		return;
	if (k > -1) {
		cout << "����: " << sitename[c] << endl;
		cout << "����� ��������: " << number[c] << endl;
		cout << "Email: " << email[c] << endl;
		cout << "������ : " << password[c] << endl << endl;
		system("read");
	}
}
void printAll() {
	if (k > -1) {
		for (int i = 0; i <= k; i++) {
			print(i);
		}
	}
}

void updtinfo(int c) {
	string check = "";
	cout << "������� �������� �����: ";
	cin >> check;
	if (checksite(check)) {
		sitename[c] = check;
	}
	else {
		cout << endl << "����� ���� ��� ���� � ������" << endl;
		return;
	}
	cout << "�������: ";
	cin >> number[c];
	cout << "Email: ";
	cin >> email[c];
	cout << "������: ";
	cin >> password[c];
}
void delSite(int c) {
	sitename[c] = "";
	number[c] = "";
	email[c] = "";
	password[c] = "";
}
int find() {
	if (k < 0)
		return -1;

	string check;
	cout << "������� �������� �����: ";
	cin >> check;
	for (int i = 0; i <= k; i++) {
		if (sitename[i] == check) {
			return i;
		}
	}
	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char op;
	do {
		system("cls");
		cout << "1. �������� ����" << endl;
		cout << "2. ������ ���� ������" << endl;
		cout << "3. �����" << endl;
		cout << "4. �������� ����������" << endl;
		cout << "5. ������� ����������" << endl;
		cout << "6. ����� �� ���������" << endl << endl;
		cout << "�������� �����:";
		cin >> op;

		switch (op) {
		case '1':
		{
			add();
			cout << "���� ��������" << endl;
			system("pause");
			break;
		}
		case '2':
		{
			printAll();
			break;
		}
		case '3':
		{
			int c = find();
			if (c > -1) {
				print(c);
			}
			break;
		}
		case '4':
		{
			int c = find();
			if (c > -1) {
				updtinfo(c);
			}
			break;
		}
		case '5':
		{
			int c = find();
			if (c > -1) {
				delSite(c);
			}
			break;
		}
		case '6':
		{
			ofstream out("sitename.txt");
			for (int i = 0; i < 50; i++) {
				out << sitename[i];
			}
			out.close();
		}
		case '7':
		{
			continue;
			break;
		}
		}

	} while (op != '7');
	
	return 0;

}