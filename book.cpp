#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

string sitename[50];
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
	cout << "Введите сайт: ";
	cin >> check;
	if (checksite(check) == 1) {
		k++;
		sitename[k] = check;
	}
	else {
		cout << endl << "Вы уже вводили данные с этого сайта" << endl;
		return;
	}
	cout << "Введите номер телефона: ";
	cin >> number[k];
	cout << "Введите почту: ";
	cin >> email[k];
	cout << "Введите пароль: ";
	cin >> password[k];
}
void print(int c) {
	if (sitename[c] == "")
		return;
	if (k > -1) {
		cout << "Сайт: " << sitename[c] << endl;
		cout << "Номер телефона: " << number[c] << endl;
		cout << "Email: " << email[c] << endl;
		cout << "Пароль : " << password[c] << endl << endl;
		cout << "Чтобы продолжить нажмите любую кнопку" << endl << endl;
		getch();
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
	cout << "Введите название сайта: ";
	cin >> check;
	if (checksite(check)) {
		sitename[c] = check;
	}
	else {
		cout << endl << "Такой сайт уже есть в списке" << endl;
		return;
	}
	cout << "Телефон: ";
	cin >> number[c];
	cout << "Email: ";
	cin >> email[c];
	cout << "Пароль: ";
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
	cout << "Введите название сайта: ";
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
		cout << "1. Добавить сайт" << endl;
		cout << "2. Список всех сайтов" << endl;
		cout << "3. Поиск" << endl;
		cout << "4. Обновить информацию" << endl;
		cout << "5. Удалить информацию" << endl;
		cout << "6. Выйти из программы" << endl << endl;
		cout << "Выберите опцию:";
		cin >> op;

		switch (op) {
		case '1':
		{
			add();
			cout << "Сайт добавлен" << endl;
			cout << "Нажмите любую кнопку, чтобы продолжить";
			getch();
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
			continue;
			break;
		}
		}

	} while (op != '6');

	return 0;

}