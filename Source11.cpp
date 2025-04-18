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
        cin>>name;
        cout << "Entre your roll no: ";
        cin >> roll_no;
        cout << "Entre your department: ";
        cin >> Department;
        cout << "Entre your gpa: ";
        cin >> gpa;

        if (!f.is_open()) {
            cout << "ERROR!";
        }
        else {
            f << name << "			" << roll_no << "			" << Department << "			" << gpa << endl;
        }

        cout << "Do you want to entre more data\nif yes them entre 1\nelse entre any number: ";
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
    cout << "press 1 for Search Student by Roll Number\npress 2 for Update Student GPA\npress 3 for Delete Student Record\n";
    cout<< "Your choice: ";
    cin >> a;

    switch (a) {
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
        cout << "you entre wrong choice\n";
    }
    return 0;
}

void search() {
    string a;
    cout << "entre roll number: ";
    cin >> a;

    ifstream f1("data.txt");
    string name, roll, dp, gpa;
    bool found = false;

    while (f1 >> name >> roll >> dp >> gpa) {
        if (roll == a) {
            cout << name << "           " << roll << "          " << dp << "            " << gpa << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
    f1.close();
}

void eddit_gpa() {
    string a, b;
    cout << "entre roll number: ";
    cin >> a;
    cout << "entre new gpa: ";
    cin >> b;

    ifstream f1("data.txt");
    ofstream f2("temp.txt");
    string name, roll, dp, gpa;
    bool found = false;

    while (f1 >> name >> roll >> dp >> gpa) {
        if (roll == a) {
            f2 << name << "\t\t\t" << roll << "\t\t\t" << dp << "\t\t\t" << b << endl;
            found = true;
        }
        else {
            f2 << name << "\t\t\t" << roll << "\t\t\t" << dp << "\t\t\t" << gpa << endl;
        }
    }

    f1.close();
    f2.close();

    if (found) {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        cout << "GPA updated successfully!\n";
    }
    else {
        remove("temp.txt");
        cout << "Student not found!\n";
    }
}

void del() {
    string a;
    cout << "entre roll number: ";
    cin >> a;

    ifstream f1("data.txt");
    ofstream f2("temp.txt");
    string name, roll, dp, gpa;
    bool found = false;

    while (f1 >> name >> roll >> dp >> gpa) {
        if (roll == a) {
            found = true;
            continue; // Skip writing this record
        }
        f2 << name << "\t\t\t" << roll << "\t\t\t" << dp << "\t\t\t" << gpa << endl;
    }

    f1.close();
    f2.close();

    if (found) {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        cout << "Record deleted successfully!\n";
    }
    else {
        remove("temp.txt");
        cout << "Student not found!\n";
    }
}