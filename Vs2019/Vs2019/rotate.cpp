#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int k = 3;
	vector<int> nums(7);
	nums = { 1,2,3,4,5,6 ,7 };
	int temp1, nexti;
	int cout = __gcd(k, nums.size());

	for (int i = 0; i < k; i++) {
		temp1 = nums[i];
		nexti = i;
		do {
			nexti = (nexti + k) % nums.size();
			swap(temp1, nums[nexti]);

		} while (nexti != i);

	}



return 0;
}