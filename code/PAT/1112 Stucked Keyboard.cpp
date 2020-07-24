#include<iostream>
#include<string>
using namespace std;

int stuck[1000] = { 0 };

int main() {
	string s1, res;
	int k;
	bool flag;
	cin >> k;
	getchar();
	getline(cin, s1);
	for (int i = 0,j; i < s1.size();) {
		switch (stuck[s1[i]])
		{
		case 0:
		case 1:
			if (i + k <= s1.size()) {
				flag = false;
				for (j = 1; j < k; j++) {
					if (s1[i] != s1[i + j]) {
						flag = true;
						break;
					}
				}
				if (flag) {
					stuck[s1[i]] = 2;
					i++;
				}
				else {
					if (stuck[s1[i]] == 0) {
						res += s1[i];
					}
					stuck[s1[i]] = 1;			
					i += k;
				}
			}
			else {
				stuck[s1[i]] = 2;
				i++;
			}
			
			break;
		case 2:
			i++;
		}
	}

	for (int i = 0; i < res.size(); i++) {
		if(stuck[res[i]]==1)
		cout << res[i];
	}
	cout << endl;
	for (int i = 0; i < s1.size(); ) {
		
		cout << s1[i];
		if (stuck[s1[i]] == 1) {
			i += k;
		}
		else {
			i++;
		}
	}
	return 0;
}