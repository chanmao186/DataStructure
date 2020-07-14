#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define N 2505
vector<string> coures[N];

bool comp(string& s1, string& s2) {
	return s1 < s2;
}

int main() {
	int n, k,c,temp;
	cin >> n >> k;
	string student;
	
	for (int i = 0; i < n; i++) {
		student.resize(4);
		cin >> student;
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> temp;
			coures[temp].push_back(student);
		}
	}

	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, coures[i].size());
		sort(coures[i].begin(), coures[i].end(), comp);
		for (auto& s : coures[i]) {
			printf("%s", s.c_str());
		}
	}

	return 0;
}

/*
scanf("%s",&s[0])

printf("%s",s.c_str())
cin cout都比较花费时间
*/