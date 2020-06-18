#include<iostream>
#include<vector>
using namespace std;
vector<int> digiti;
vector<int> digito;
//输入的各个数字的个数
int numi[10] = { 0 };
int numo[10] = { 0 };
int main() {
	string input;
	int temp, n;
	cin >> input;
	n = input.length();
	for (auto c : input) {
		temp = c - '0';
		digiti.push_back(temp);
		numi[temp]++;
	}
	bool flag = true;
	if (digiti[0] < 5) {
		digito.push_back(digiti[0] * 2);
	}
	else {
		flag = false;
		digito.push_back(1);
		digito.push_back(digiti[0] * 2 % 10);
	}
	//numo[digito[0]]++;
	for (int i = 1; i < n; i++) {
		temp = digiti[i] * 2;
		if (temp > 9) {
			(digito[digito.size()-1])++;
			digito.push_back(temp % 10);
		}
		else {
			digito.push_back(temp);
		}
	}
	for (auto x : digito) {
		numo[x]++;
	}
	for (int i = 0; i < 10; i++) {
		if (numi[i] != numo[i]) {
			flag = false;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	for (auto x : digito) {
		cout << x;
	}

	return 0;
}