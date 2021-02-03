#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int k = 1;
	string  s = "AABABBA";
	bool isfind = false;
	int start = 0, max = 0, cur = 1, n = s.size(), ck;

	while ((start + max) < n) {
		ck = k;
		cur = 1;
		isfind = false;


		for (int i = start + 1; i < n; i++) {
			if (s[i] != s[start]) {
				if (!isfind) {
					isfind = true;
					start = i;
				}

				if (ck-- == 0)break;

			}
			cur++;
		}

		if (cur > max) {
			max = cur;
		}
	}

	return  max;
	return 0;
}