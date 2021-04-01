#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())return s;
		bool flag[1005][1005] = { false };
		string res;
		res += s[0];
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			flag[i][i] = true;
		}
		for (int i, j, k = 2; k <= n; ++k) {
			for (i = 0, j = k - 1; j < n; ++i, ++j) {
				if (s[i] == s[j] && (flag[i + 1][j - 1] || k == 2)) {
					flag[i][j] = true;
					res = s.substr(i, j+1);
				}

			}
		}
		return res;
	}



};

int main() {
	string s = "babad";
	string ss=  s.substr(1, 3);
	Solution f;
	f.longestPalindrome(s);
	return 0;
}