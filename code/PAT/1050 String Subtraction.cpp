#include<iostream>
#include<string>
using namespace std;

bool alp[10000] = { false };

int main() {
	string s1, s2,res;
	getline(cin, s1);
	getline(cin, s2);
	for (auto c : s2) {
		alp[c] = true;
	}
	for (auto& c : s1) {
		if (alp[c])continue;
		res += c;
	}
	cout << res << endl;
	return 0;
}