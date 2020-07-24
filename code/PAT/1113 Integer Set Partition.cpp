#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>num;
int main() {
	int N,temp,n1,s1=0,s2=0,i;
	cin >> N;
	for (i=0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	n1 = N / 2;
	for (i = 0; i < n1; i++) {
		s1 += num[i];
	}

	for (; i < N; i++) {
		s2 += num[i];
	}
	printf("%d %d", N % 2, s2-s1);
	return 0;
}