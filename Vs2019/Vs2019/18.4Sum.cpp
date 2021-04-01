#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>>res;
		if (nums.size() < 4)return res;
		int last1 = nums.size() - 3, last2 = last1 + 1, pre1, pre2, temp;
		pre1 = pre2 = 0x7fffffff;
		for (int i = 0, j, k, l; i < last1; ++i) {
			while (pre1 == nums[i]) {
				++i;
				if (j == last1) {
					return res;
				}
			};//去重
			pre1 = nums[i];
			pre2 = 0x7fffffff;
			for (j = i + 1; j < last2; ++j) {
				while (pre2 == nums[j] && j < last2) {
					++j;
				};//去重
				if (j == last2)break;
				pre2 = nums[j];
				k = j + 1;
				l = last2 + 1;
				while (k < l) {
					temp = nums[i] + nums[j] + nums[k] + nums[l];
					if (temp < target) {
						++k;
					}
					else if (temp > target) {
						--l;
					}
					else {
						if (k == j + 1 || nums[k - 1] != nums[k]) {
							res.push_back({ nums[i],nums[j],nums[k],nums[l] });
						}
						++k;
					}
				}
			}
		}
		return res;
	}
};
int main() {
	string s = "babad";
	vector<int> ss;
	ss = { 1,0,-1,0,-2,2};

	Solution f;
	f.fourSum(ss, 0);
	return 0;
}