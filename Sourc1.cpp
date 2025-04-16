/*COD 1:-*/
#include <iostream>
using namespace std;
int take(int b[8]);
int main() {
	int a[8];
	for (int i = 0; i <= 7; i++){
		cin >> a[i];
	}
	take(a);
	return 0;
}
int  take(int b[8]){
	for (int i = 0; i <= 7; i++){
		cout << b[i];
	}
	return 0;
}
