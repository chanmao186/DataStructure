#include<iostream>
#include<cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n3 =ceil(( s.length()+2) / 3.0);//必须是float类型
	
	if ((s.length() - n3) % 2 == 1) {
		n3++;
	}
	int n1 = (s.length() - n3) / 2;
	string blank = "";
	int i = 0;
	for (; i < n3 - 2; i++) {
		blank += " ";
	}
	for (i = 0; i < n1; i++) {
		cout << s[i] << blank << s[s.length() - i - 1] << endl;
	}
	for (; i < s.length() - n1; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}