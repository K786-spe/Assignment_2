
//
//
//Add Player Record
//•	player’s name, team name, role(batsman / bowler / all - rounder), total runs, and wickets.
//•	Save the record in a file players.txt.
//View All Players
//
//Search Player by Name or Team
//•	Allow searching for players either by name or by team.
//Update Player Stats
//•	Update player’s runs or wickets based on recent matches.

//Delete Player Record
//•	Delete a player's record from the file using their name.





#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void search();
void update();
void del();


int main() {
	int q;
	cout << "Entre 1 if you whant to entre data\n Entre any numbe outher number othe yhen 1 if you want to do any other thing\n";
	cin >> q;


	if (q == 1)
	{

		string p_name, t_name, role, runs, wickets;
		ofstream f("manue.txt", ios::app);
		int c = 1;
		while (c == 1) {
			cout << "entre name of plare: ";
			cin >> p_name;
			cout << "entre name of teem: ";
			cin >> t_name;
			cout << "entre role of plare: ";
			cin >> role;
			cout << "entre totle run's: ";
			cin >> runs;
			cout << "entre wichets: ";
			cin >> wickets;


			if (!f.is_open()) {
				cout << "ERROR!";
			}
			else
			{
				f << p_name << "		" << t_name << "		" << role << "		" << runs << "		" << wickets << endl;
			}

			cout << "Do you want to entre more data\nif yes them entre 1\nelse entre any number you want but you must entre any number\n" << endl;
			cin >> c;

		}
		f.close();
		cout << "====================================================================================\n=====================================================================================";
		ifstream f1("manue.txt");
		string s;
		cout << endl;
		while (getline(f1, s)) {
			cout << s << endl;
		}

		cout << "=====================================================================================\n=====================================================================================";

	}
	else
	{
		int choice;
		cout << "1:for search\n2:for Update Player Stats\n3:For Delete Player Record\nEntre: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			search();
			break;
		case 2:
			update();
			break;
		case 3:
			del();
			break;
		default:
			cout << "you entre rong choice." << endl;
			break;
		}
	}
	
	return 0;
}





void search() {
	string name, team;
	int a;
	cout << "1: For search by plare's name\n2: For search by teem name\nentre: ";
	cin >> a;

	ifstream f("manue.txt");
	string p_name, t_name, role, runs, wickets;
	bool found = false;

	if (!f.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	if (a == 1) {
		cout << "Entre name: ";
		cin >> name;
	}
	else if (a == 2) {
		cout << "Entre name: ";
		cin >> team;
	}

	while (f >> p_name >> t_name >> role >> runs >> wickets) {
		if ((a == 1 && name == p_name) || (a == 2 && team == t_name)) {
			cout << p_name << " " << t_name << " " << role << " " << runs << " " << wickets << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Record not found.\n";
	}

	f.close();
}








void update() {
	string name;
	cout << "Entre plare name to update: ";
	cin >> name;

	ifstream f("manue.txt");
	ofstream temp("temp.txt");

	string p_name, t_name, role, runs, wickets;
	bool updated = false;

	while (f >> p_name >> t_name >> role >> runs >> wickets) {
		if (p_name == name) {
			cout << "Entre new runs: ";
			cin >> runs;
			cout << "Entre new wickets: ";
			cin >> wickets;
			updated = true;
		}
		temp << p_name << "		" << t_name << "		" << role << "		" << runs << "		" << wickets << endl;
	}

	f.close();
	temp.close();

	remove("manue.txt");
	rename("temp.txt", "manue.txt");

	if (updated)
		cout << "Plare record updated successfully.\n";
	else
		cout << "Plare not found.\n";
}











void del() {
	string name;
	cout << "Entre plare name to delete: ";
	cin >> name;

	ifstream f("manue.txt");
	ofstream temp("temp.txt");

	string p_name, t_name, role, runs, wickets;
	bool deleted = false;

	while (f >> p_name >> t_name >> role >> runs >> wickets) {
		if (p_name != name) {
			temp << p_name << " " << t_name << " " << role << " " << runs << " " << wickets << endl;
		}
		else {
			deleted = true;
		}
	}

	f.close();
	temp.close();

	remove("manue.txt");
	rename("temp.txt", "manue.txt");

	if (deleted)
		cout << "Plare record deleted successfully.\n";
	else
		cout << "Plare not found.\n";
}
