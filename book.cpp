#include<iostream>
#include<stdlib.h>
#include <fstream>

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
		ifstream in("sitename.txt");
		for (int i = 0; i < 50; i++) {
			in >> sitename[i];
			in >> number[i];
			in >> email[i];
			in >> password[i];
		}

		in.close();
		system("cls");	
		cout << "1. Add website" << endl;
		cout << "2. List of all websites" << endl;
		cout << "3. Search" << endl;
		cout << "4. Update" << endl;
		cout << "5. Delete" << endl;
		cout << "6. Save" << endl;
		cout << "7. Exit" << endl << endl;
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
		case '7':
		{
			continue;
			break;
		}
		}

	} while (op != '7');

	return 0;

}