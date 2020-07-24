#include<iostream>
#include<unordered_map>
using namespace std;
//vector<char> res;
int color1[1000] = { 0 };
int color2[1000] = { 0 };

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int s = 0;
	for (auto& c : s1) {
		color1[c]++;
	}

	for (auto& c : s2) {
		color2[c]++;
	}


	for (auto& c : s2) {
		if (color1[c] <= 0) {
			s++;
		}
		else {
			color1[c]--;
		}
	}

	if (s == 0) {
		printf("Yes %d", s1.size() - s2.size());
	}
	else {
		printf("No ");

		printf("%d", s);
	}
	return 0;
}