#include <iostream>
using namespace std;

int main() { 
	string radix = "0123456789ABC";
	int color[3];
	cout << "#";
	for (int i = 0; i < 3; i++) {
		cin >> color[i];
		cout << radix[color[i] / 13];
		cout << radix[color[i] % 13];
	}
	cout << endl;
	return 0;
}