#include<iostream>
using namespace std;
int sign;
struct Num {
	string orig;
	int k = 0;
	string stad = "";	
	void op() {
		int i = 0, j = 0;
		bool ishave = false;
		if (sign == 0) {
			stad = "0";
			return;
		}

		//去掉数字前面的0;
		for (; i + 1 < orig.length(); i++) {
			if (orig[i] == '0' && orig[i + 1] == '0') {
				continue;
			}
			break;
		}

		if (i + 1 < orig.length()&&orig[i] == '0' && orig[i + 1] != '.') {
			i++;
		}

		if (orig[i] == '0') {
			k = 0;
			for (i += 2; i < orig.length(); i++) {
				if (orig[i] != '0') {
					ishave = true;
					break;
				}
				k--;
			}
			if (!ishave) {
				k = 0;
			}
		}
		else {
			for (j = i; j < orig.length(); j++) {
				if (orig[j] == '.')break;
				k++;
			}
		}	


		for (j=0; i < orig.length() && j < sign; i++) {
			if (orig[i] == '.')continue;
			stad += orig[i];
			j++;
		}
		for (; j < sign; j++) {
			stad += '0';
		}

	}

	void output() {
		printf("0.%s*10^%d", stad.c_str(), k);
	}
};

int main() {

	Num n1, n2;
	cin >> sign >> n1.orig >> n2.orig;
	n1.op(); n2.op();
	if (n1.k == n2.k && n1.stad == n2.stad) {
		printf("YES ");
		n1.output();
	}
	else {
		printf("NO ");
		n1.output();
		printf(" ");
		n2.output();
	}

	return 0;
}