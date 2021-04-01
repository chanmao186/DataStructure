#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.size() < k)return 0;
		int nums[26] = { 0 };
		for (auto& c : s) {
			++nums[c - 'a'];
		}


		int res = 0, i = 0, pre = 0;
		bool flag = true;


		for (; i < s.size(); ++i) {
			if (nums[s[i] - 'a'] < k) {
				flag = false;
				res = max(res, longestSubstring(s.substr(pre, i - pre), k));
				pre = i+1;
			}
		}
		if (flag)return s.size();
		return max(res, longestSubstring(s.substr(pre, i - pre), k));
	}
};
int main() {
	string s = "bbaaacbd";
	vector<int> ss;
	ss = { 1,0,-1,0,-2,2 };

	Solution f;
	f.longestSubstring(s, 3);
	return 0;
}