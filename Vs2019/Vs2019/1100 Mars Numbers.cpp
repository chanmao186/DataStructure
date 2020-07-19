#include<iostream>
#include<vector>
#include<string>
using namespace std;
string MarNum1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string MarNum2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main() {
	int N;
	cin >> N;
	string orig,n1,n2;

	int num,_n1,_n2;
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, orig);
		if (isalpha(orig[0])){
			if (orig == "tret") {
				printf("0");
			}
			else if (orig.length() > 3) {
				n1 = orig.substr(0, 3);
				n2 = orig.substr(4, 3);
				for (_n1 = 0; _n1 < 13; _n1++) {
					if (n1 == MarNum2[_n1]) {
						break;
					}
				}
				for (_n2 = 0; _n2 < 13; _n2++) {
					if (n2 == MarNum1[_n2]) {
						break;
					}
				}

				printf("%d", _n1 * 13 + _n2);
			}
			else {
				for (_n1 = 0; _n1 < 13; _n1++) {
					if (orig == MarNum1[_n1]) {
						printf("%d", _n1);
						break;
					}
				}
				for (_n1 = 0; _n1 < 13; _n1++) {
					if (orig == MarNum2[_n1]) {
						printf("%d", _n1*13);
						break;
					}
				}
			}
		}
		else {
			num = atoi(orig.c_str());
            if(num<13){
				printf("%s", MarNum1[num].c_str());
			}
			else {
				printf("%s", MarNum2[num / 13].c_str());
				if (num % 13!=0) {
					printf(" %s", MarNum1[num % 13].c_str());
				}
			}
		}
		printf("\n");
	}
	return 0;
}