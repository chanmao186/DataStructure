#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string Input;
	
	getline(cin,Input);
	int temp, maxn = -1;
	if (Input.length() == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i < Input.length(); i++) {
		temp = 0;
		for (int j = 0; i - j - 1>=0&& i + j < Input.length() &&(Input[i + j] == Input[i - j - 1]); j++) {
			temp+=2;
		}
		maxn = max(temp, maxn);
		temp = 1;
		for (int j = 1;i-j>=0 && i + j < Input.length() &&Input[i + j] == Input[i - j]; j++) {
			temp+=2;
		}
		maxn=max(maxn, temp);
	}

	cout << maxn << endl;
	return 0;
}