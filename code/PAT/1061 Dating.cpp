#include<iostream>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN" };
int main() {
	int r1, r2, r3;
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int i = 0;
	for (; i < s1.length() && i < s2.size(); i++) {
		if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
			r1 = s1[i] - 'A';
			cout << week[r1];
			break;
		}
	}	
	for (i++; i < s1.length() && i < s2.size(); i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] >= '0' && s1[i] <= '9') {
				r2 = s1[i] - '0';
				break;
			}
			else if(s1[i] >= 'A' && s1[i] <= 'N'){
				r2 = s1[i] - 'A' + 10;
				break;
			}		
		}
	}
	r3 = 0;
	for (i = 0; i < s3.length() && i < s4.length(); i++) {
		if (s3[i] == s4[i]&&s3[i]) {
			if (isalpha(s3[i])) {
				break;
			}
		}
	}
	printf(" %02d:%02d", r2, i);
	return 0;
}