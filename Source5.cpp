
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