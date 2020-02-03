#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num, base;
	cin >> num >> base;
	vector<int> result;
	while (num / base != 0) {
		result.push_back(num % base);
		num /= base;
	}
	if (num > 0 || result.size() == 0) {
		result.push_back(num);
	}
	reverse(result.begin(), result.end());
	bool flag = true;
	int size = result.size() / 2;
	int last = result.size() - 1;
	for (int i = 0; i < size; i++) {
		if (result[i] != result[last - i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << result[0];
	for (int i = 1; i < result.size(); i++) {
		cout << " " << result[i];
	}
	cout << endl;
	return 0;
}