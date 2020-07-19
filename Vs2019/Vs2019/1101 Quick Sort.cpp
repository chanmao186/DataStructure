#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long num[100005];
vector<long long>res;
long long inf = 10e10;
int N;

vector<int>s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		s.push_back(num[i]);
	}
	sort(s.begin(), s.end());
	int left = num[0];

	for (int i = 0; i < N; i++) {
		if (left <= num[i] && num[i] == s[i]) {
			res.push_back(s[i]);
		}
		if (left < num[i]) {
			left = num[i];
		}
	}

	sort(res.begin(), res.end());
	printf("%d\n", res.size());

	if (res.size() == 0) {
		cout <<  endl;
		return 0;
	}

	cout << res[0];
	for (int i = 1; i < res.size(); i++) {
		cout << " " << res[i];
	}
	return 0;
}