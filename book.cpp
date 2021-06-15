#include<iostream>
#include<stdlib.h>
#include <fstream>
#include<string>
#include <ctime>

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
	cout << "Enter website: ";
	cin >> check;

	if (checksite(check) == 1) {
		k++;
		sitename[k] = check;
	}
	else {
		cout << endl << "You have already entered data from this website" << endl;
		return;
	}
	cout << "Enter phone nubmer: ";
	cin >> number[k];
	cout << "Enter email: ";
	cin >> email[k];
	cout << "Enter password: ";
	cin >> password[k];
}
void print(int c) {
	if (sitename[c] == "")
		return;
	if (k > -1) {
		cout << "Website: " << sitename[c] << endl;
		cout << "phone nubmer: " << number[c] << endl;
		cout << "Email: " << email[c] << endl;
		cout << "password: " << password[c] << endl << endl;
		system("pause");
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
	cout << "Enter website: ";
	cin >> check;
	if (checksite(check)) {
		sitename[c] = check;
	}
	else {
		cout << endl << "You have already entered data from this website" << endl;
		return;
	}
	cout << "Phone number: ";
	cin >> number[c];
	cout << "Email: ";
	cin >> email[c];
	cout << "password: ";
	cin >> password[c];
}
void delSite(int c) {
	sitename[c] = "";
	number[c] = "";
	email[c] = "";
	password[c] = "";
}
void Generate() {
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	int level;
	int length;
	do {
		cout << "1-Weak   ****  2-Average  ****  3-Strong" << endl;
		cout << "Please enter password complexity. " << endl;
		cin >> level;

		if (level < 1 || level>3)
			cout << "Invalid Complexity Entered. Please Re-Enter" << endl;
	} while (level < 1 || level>3);

	if (level == 1) length = 8;
	else if (level == 2) length = 14;
	else length = 20;

	char pass[21] = "";

	int i;
	for (i = 0; i < length; i++) {
		if (level == 1) {
			if (rand() % 3 == 0)
				pass[i] = 86 + rand() % 34;
			else
				pass[i] = 46 + rand() % 10;
		}
		else if (level == 2) {
			if (rand() % 4 == 0)
				pass[i] = 86 + rand() % 34;
			else if (rand() % 3 == 1)
				pass[i] = 53 + rand() % 26;
			else
				pass[i] = 46 + rand() % 10;
		}
		else if (level == 3) {
			if (rand() % 5 == 0)
				pass[i] = 86 + rand() % 34;
			else if (rand() % 4 == 1)
				pass[i] = 53 + rand() % 26;
			else if (rand() % 4 == 2)
				pass[i] = 32 + rand() % 15;
			else
				pass[i] = 46 + rand() % 10;
		}
	}
	for (int i = 0; i < length; i++) {
		cout << pass[i];
	}
	cout << endl;
}

int find() {
	if (k < 0)
		return -1;

	string check;
	cout << "Enter website: ";
	cin >> check;
	for (int i = 0; i <= k; i++) {
		if (sitename[i] == check) {
			return i;
		}
	}
	return 1;
}

int main() {
	char op;
	do {

		system("cls");
		cout << "1. Add website" << endl;
		cout << "2. Generate Password" << endl;
		cout << "3. List of all websites" << endl;
		cout << "4. Search" << endl;
		cout << "5. Update" << endl;
		cout << "6. Delete" << endl;
		cout << "7. Save" << endl;
		cout << "8. Open" << endl;
		cout << "9. Exit" << endl << endl;
		cout << "Choose the option:";
		cin >> op;

		switch (op) {
		case '1':
		{
			add();
			cout << "Website added" << endl;
			system("pause");
			break;
		}
		case '2': {
			cout << "   ****      PASSWORD  GENERATOR     ***      " << endl;
			cout << "   Welcome to the Password Generator.     " << endl;
			cout << "   You can generate password and choose the difficulty level for your password." << endl << endl;
			Generate();
			system("pause");
			break;
		}
		case '3':
		{
			printAll();
			system("pause");
			break;
		}
		case '4':
		{
			int c = find();
			if (c > -1) {
				print(c);
			}
			break;
		}
		case '5':
		{
			int c = find();
			if (c > -1) {
				updtinfo(c);
			}
			break;
		}
		case '6':
		{
			int c = find();
			if (c > -1) {
				delSite(c);
			}
			break;
		}
		case '7':
		{
			ofstream out;
			out.open("sitename.txt");
			if (!out.is_open())
			{
				cerr << "error\n";
			}

			for (int i = 0; i <= k; i++) {
				out << sitename[i] << endl;
				out << number[i] << endl;
				out << email[i] << endl;
				out << password[i] << endl;
			}
			out.close();
			break;


		}

		case '8':
		{
			ifstream in;
			in.open("sitename.txt");
			for (int i = 0; i < 50; i++) {
				getline(in, sitename[i]);
				getline(in, number[i]);
				getline(in, email[i]);
				getline(in, password[i]);
			}
			int j = 0;
			while (sitename[j] != "") {
				j++;
			}
			k = j-1;
			in.close();
			system("pause");
			break;
		}
		case '9':
		{
			continue;
			break;
		}
		}
	} while (op != '9');

	return 0;

}