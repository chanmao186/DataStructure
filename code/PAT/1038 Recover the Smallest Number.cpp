#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> nums;

bool comp1(string& s1, string& s2) {
	string n1, n2;
	n1 = s1 + s2;
	n2 = s2 + s1;
	return n1 < n2;
}

bool comp(string& s1, string& s2) {
	int i = 0;
	for (; i < s1.size() && i < s2.size(); i++) {
		if (s1[i] == s2[i]) {
			continue;
		}
		return s1[i] < s2[i];
	}
	if (s1.size() == s2.size()) {
		return true;
	}
	int j;
	if (i == s1.size()) {
		while (i < s2.size())
		{
			for (j = 0; i < s2.size() && j < s1.size(); i++, j++) {
				if (s1[j] == s2[i])continue;
				return s1[j] < s2[i];
			}
		}
		i--;
		for (j--; i < s2.size() && j < s1.size(); j++) {
			if (s1[j] == s2[i])continue;
			return s1[j] < s2[i];
		}

		return true;
	}

	if (i == s2.size()) {
		while (i < s1.size())
		{
			for (j = 0; i < s1.size() && j < s2.size(); i++, j++) {
				if (s2[j] == s1[i])continue;
				return s1[i] < s2[j];
			}
		}
		i--;
		for (j--; i < s1.size() && j < s2.size(); j++) {
			if (s1[i] == s2[j])continue;
			return s1[i] < s2[j];
		}

		return true;
	}
	return true;
}

int main() {
	int N, i;
	string num;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), comp1);
	bool flag = false;
	string res;
	for (i = 0; i < N && !flag; i++) {
		num = nums[i];
		for (auto n : num) {
			if (!flag && n == '0')continue;
			flag = true;
			res += n;
		}
	}
	for (; i < N; i++) {
		res += nums[i];
	}
	if (res.size() == 0) {
		cout << "0" << endl;
	}
	else
	{
		cout << res << endl;
	}
	//cout << endl;
	return 0;
}