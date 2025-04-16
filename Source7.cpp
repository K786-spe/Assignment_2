#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int countIntegers(); 

int main() {
   
    int numIntegers = countIntegers(); 
    cout << "Number of integers in the file: " << numIntegers << endl;
    return 0;
}

int countIntegers() {
    ifstream file("input.txt");
    int count = 0;
    string num;
    if (file.is_open()) {
        while (file >> num) { 
            count++;
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open file for reading.\n";
    }
    return count;
}

