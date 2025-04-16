//COD 3:-
#include <iostream>
using namespace std;
int vovels(char a[8]);
int main() {
	char s[8];
	for (int i = 0; i <= 7; i++){
		cin >> s[i];
	}
	int num = vovels(s);
	cout << "number of vovels are: " << num;
	return 0;
}
int vovels(char a[8]){
	int num = 0;
	for (int i = 0; i <= 7; i++){
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
			num++;
		}
	}
	return num;
}
