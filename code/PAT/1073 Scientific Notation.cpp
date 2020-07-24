#include<iostream>
using namespace std;
string orig;
int main() {
	cin >> orig;
	string num, es,temp,val;
	int i=0, e;
	val += orig[0];
	if (val[0] == '+' || val[0] == '-') {
		i++;
	}
	for (; i < orig.length(); i++) {
		if (orig[i] == 'E')break;
		if (orig[i] == '.' || orig[i] == '+')continue;
		num += orig[i];
	}
	for (i++; i < orig.length(); i++) {
		es += orig[i];
	}
	e = atoi(es.c_str());
	if (e < 0) {
		e = abs(e);
		temp = "0.";
		for (i = 1; i < e; i++) {
			temp += '0';
		}
		temp += num;
	}
	else if(e>=0) {
		temp = num[0];
		if (e + 1 < num.length()) {
			for (i = 1; i - 1 < e; i++) {
				temp += num[i];
			}
			temp += ".";
			for (; i < num.length(); i++) {
				temp += num[i];
			}
		}
		else {
			temp = num;
			e = e + 1 - num.length();
			for (i = 0; i < e; i++) {
				temp += "0";
			}
		}						
	}
	if (val == "-") {
		cout << val;
	}
	cout << temp << endl;
	return 0;
}