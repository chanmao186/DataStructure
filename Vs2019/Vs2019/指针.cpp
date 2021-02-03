#include<iostream>
#include<string>
#include <vector>
using namespace std;
int main()
{
	const int c = 1;
	const int* a = &c;
	int* b = const_cast<int*>(a);
	*b = 3;
	cout << b << endl << &c << endl << a << endl;
	cout << *b << endl << *a << endl << c << endl;
	int d = c;
	cout << d << endl;
	return 0;
}