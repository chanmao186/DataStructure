#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<int> nums(4);

bool issame() {
	int n = nums[0];
	for (int i = 0; i < 4; i++) {
		if (n != nums[i])
			return false;
	}
	return true;
}

void updatenum(int n) {
	nums[0] = n / 1000;
	nums[1] = n % 1000 / 100;
	nums[2] = n % 100 / 10;
	nums[3] = n % 10;
	sort(nums.begin(), nums.end());
}

int getMax() {
	int temp = 0;
	temp += nums[0];
	temp += nums[1] * 10;
	temp += nums[2] * 100;
	temp += nums[3] * 1000;
	return temp;
}
int getMin() {
	int temp = 0;
	temp += nums[3];
	temp += nums[2] * 10;
	temp += nums[1] * 100;
	temp += nums[0] * 1000;
	return temp;
}
int main() {
	int m1, m2, m3, i;
	cin >> m3;
	
	if (m3 == 0) {
		printf("\n");
		return 0;
	}
	do{
		updatenum(m3);
		m1 = getMax();
		m2 = getMin();
		m3 = m1 - m2;
		printf("%04d - %04d = %04d\n", m1, m2, m3);
		if (issame()) { 
			break;
		}
	} while (m3 != 6174);

	return 0;
}