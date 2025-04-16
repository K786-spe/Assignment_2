//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main(){
//	ofstream file;
//	char a[50];
//	cout << "entre string: ";
//	cin.getline(a,50);
//	cout << a;
//	system("pause");
//	file.open("output.txt");
//	if (file.is_open()){
//		for (int i = 0; a[i] != '\0'; i++){
//			file << a[i];
//		}
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
void print(char a[50]);
int main(){
	char b[50];
	cout << "entre a line: ";
	cin.getline(b, 50);
	print(b);

	return 0;
}
void print(char a[50]){
	cout << "char array is: ";
	for (int i = 0; a[i] != '\0'; i++){
		cout << a[i];
	}
	system("pause");
	return 0;
}