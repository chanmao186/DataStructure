#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
struct Polynomial {
	int Exponent;
	float Cofficent;
};
int main() {
	float K[2005] = { 0 };
	vector<Polynomial>	p1, p2, p3;
	int n, exponent;
	float cofficent;
	Polynomial num;
	cin >> n;
	while (n--)
	{
		cin >> num.Exponent >> num.Cofficent;
		p1.push_back(num);
	}
	cin >> n;
	while (n--)
	{
		cin >> num.Exponent >> num.Cofficent;
		p2.push_back(num);
	}
	for (auto x : p1) {
		for (auto y : p2) {
			exponent = x.Exponent + y.Exponent;
			cofficent = x.Cofficent * y.Cofficent;
			K[exponent] += cofficent;
		}
	}
	for (n = 2004; n >= 0; n--) {
		if (K[n] != 0.0) {
			num.Exponent = n;
			num.Cofficent = K[n];
			p3.push_back(num);
		}
	}
	cout << p3.size();

	for (auto x : p3) {
		printf(" %d %.1f", x.Exponent, x.Cofficent);
	}
	return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/