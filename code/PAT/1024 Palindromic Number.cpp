#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num;
vector<int> num1;
int k = 0;
int MAX;
bool isPalindromic() {
	for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
		if (num[i] != num[j]) {
			return false;
		}
	}
	return true;
}

void Step() {
	num1 = num;
	reverse(num1.begin(), num1.end());
	//进位标志
	bool flag = false;
	int temp;
	for (int i = 0; i < num.size(); i++) {
		temp = num[i] + num1[i];
		if (flag) {
			//进位
			temp++;
			flag = false;
		}
		if (temp > 9) {
			temp -= 10;
			flag = true;
		}
		num[i] = temp;
	}
	if (flag) {
		num.push_back(1);
	}
	k++;
}
int main() {
	string n;
	cin >> n >> MAX;
	for (int i = n.length() - 1; i >= 0; i--) {
		num.push_back(n[i] - '0');
	}

	while (k < MAX && !isPalindromic()) {
		Step();
	}
	reverse(num.begin(), num.end());
	for (auto x : num) {
		cout << x;
	}
	cout << endl;
	cout << k << endl;
	return 0;
}
