//Add Student Record
// fields:
//•	Name
//•	Roll Number
//•	Department
//•	GPA
//The function should store this data in a text file named students.txt using file handling in append mode.

//Search Student by Roll Number
//Update Student GPA
//Delete Student Record



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void search();
void eddit_gpa();
void del();

int main() {
	int c = 1;
	ofstream f("data.txt", ios::app);
	string name, roll_no, Department, gpa;
	while (c == 1) {
		cout << "Enter your name: ";
		cin >> name;
		cout << "Entre your roll no: ";
		cin >> roll_no;
		cout << "Entre your department: ";
		cin >> Department;
		cout << "Entre your gpa: ";
		cin >> gpa;
		if (!f.is_open()) {
			cout << "ERROR!";
		}
		else
		{
			f << name << "			" << roll_no << "			" << Department << "			" << gpa << endl;
		}
		cout << "Do you want to entre more data\nif yes them entre 1\nelse entre any number you want but you must entre any number\n";
		cin >> c;

	}
	f.close();
	ifstream f1("data.txt");
	string s;
	while (getline(f1, s)) {
		cout << s << endl;
	}
	f1.close();
	int a;
	cout << "press for 1 Search Student by Roll Number\npress for 2 Update Student GPA\npress for 3 Delete Student Record";
	cin >> a;
	switch (a)
	{
	case 1:
		search();
		break;
	case 2:
		eddit_gpa();
		break;
	case 3:
		del();
		break;

	default:
		cout << "you entre rong choice\n";
	}
}
void search() {
	string a, name, roll, dp, gpa;
	cout << "entre roll number: ";
	cin >> a;
	ifstream f1("data.txt");
	string s;
	while (f1 >> name >> roll >> dp >> gpa) {
		if (roll == a) {
			cout << name << "			" << roll << "			" << dp << "			" << gpa;
		}

	}
	f1.close();
}

void eddit_gpa() {
	string a, b, name, roll, dp, gpa;
	cout << "entre roll number: ";
	cin >> a;
	cout << "entre new gpa: ";
	cin >> b;
	fstream f1("data.txt", ios::in | ios::out);
	string s;
	while (f1 >> name >> roll >> dp >> gpa) {
		if (roll == a) {
			gpa = b;
			cout << name << "			" << roll << "			" << dp << "			" << gpa;
			f1 << name << "			" << roll << "			" << dp << "			" << gpa;
		}
		else
		{
			cout << "not found!";
		}

	}
	f1.close();
}
void del() {
	string a, b, name, roll, dp, gpa;
	cout << "entre roll number: ";
	cin >> a;

	fstream f1("data.txt", ios::in | ios::out);
	string s;
	while (f1 >> name >> roll >> dp >> gpa) {
		if (roll == a) {
			gpa = b;
			cout << name << "			" << roll << "			" << dp << "			" << gpa;
			f1 << "			";
		}
		else
		{
			cout << "Not found!";
		}

	}
	f1.close();
}