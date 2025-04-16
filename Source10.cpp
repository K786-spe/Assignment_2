#include <iostream>
using namespace std;

bool reverse(char a[],int size);

int main()
{
	int l = 0;
	char arr[50];
	cout << "Entre a string: ";
	cin.getline(arr, 50);
	for (int i = 0; arr[i] != '\0'; i++) {
		l++;
	}
	if (reverse(arr,l) == true) {
		cout << "It is Pliedrom\n";
	}
	else {
		cout << "It is not a Pliedrom\n";
	}
}
bool reverse(char a[],int size) {
	char b[50];
	bool p = true;

	for (int i = 0; a[i] != '\0'; i++) {
		b[i] = a[size-1];
		size--;
	}

	for (int i = 0; a[i] != '\0'; i++) {
		if (b[i] != a[i]) {
			p = false;
		}
	}
	return p;
}