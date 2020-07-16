#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;

	for (int i = 2; i * i<= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string input;
	int N, K, num;
	cin >> N >> K >> input;
	if (input.length() < K||K==0) {
		cout << 404 << endl;
		return 0;
	}
	//string temp(input, 0, K-1);
	//对数组还是不太熟悉
	for (int i = 0; i+K <= N; i++) {
		string temp(input, i, K);
		num = atoi(temp.c_str());
		if (isPrime(num)) {
			cout << temp << endl;
			return 0;
		}
	}
	cout << 404 << endl;
	return 0;
}