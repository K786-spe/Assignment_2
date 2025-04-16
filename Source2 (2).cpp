////COD 2:-
#include <iostream>
using namespace std;

int take(int b[8]);

int main() {
	int a[8];
	for (int i = 0; i <= 7; i++) {
		cin >> a[i];
	}
	int sum = take(a);
	cout << "Sum is: " << sum;
	return 0;
}

int take(int b[8]) {
	int sum = 0;
	for (int i = 0; i <= 7; i++) {
		cout << b[i] << " "; .
			sum = sum + b[i];
	}
	cout << endl;
	return sum;
}
