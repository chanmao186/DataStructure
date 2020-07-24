#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s[105],s1;

int main() {
	int N,i,j,n1,n2,fl;
	cin >> N;
	getchar();
	for (i = 0; i < N; i++) {
		getline(cin, s[i]);
	}
	s1 = s[0];

	for (i = 1; i < N; i++) {
		if (s1.back() != s[i].back()) {
			printf("nai");
			return 0;
		}
		n1 = s1.size();
		n2 = s[i].size();
		fl = min(n1, n2);
		for (j = 1; j <=fl; j++) {
			if (s1[n1 - j] != s[i][n2 - j]) {
				s1 = s1.substr(s1.size() - j+1);
				goto ne;
			}
		}

		s1 = s1.substr(s1.size() - fl);

	ne:;
	}
	cout << s1;
	
	return 0;
}