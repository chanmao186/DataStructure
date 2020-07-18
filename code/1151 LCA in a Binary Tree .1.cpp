#include<iostream>
#include<unordered_map>
using namespace std;
#define N 10005

unordered_map<int, int>index;
int in[N], pre[N];
using namespace std;
int s1, s2;

void findA(int ps, int pe, int is, int ie) {
	int pos = index[pre[ps]];
	//int s1p=index[s1],s2p=index[s1]
	if (index[s1] == pos) {
		printf("%d is an ancestor of %d.\n", s1, s2);
	}
	else if (index[s2] == pos) {
		printf("%d is an ancestor of %d.\n", s2, s1);
	}
	else if (index[s1] > pos && index[s2] > pos) {
		//ÔÚÓÒ±ß
		findA(ps + pos - is + 1, pe, pos + 1, ie);
	}
	else if (index[s1] < pos && index[s2] < pos) {
		findA(ps + 1, ps + pos - is, is, pos - 1);
	}
	else {
		printf("LCA of %d and %d is %d.\n", s1, s2, pre[ps]);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &in[i]);
		index[in[i]] = i;
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d", &pre[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s1, &s2);
		if (index[s1] == 0 && index[s2] == 0) {
			printf("ERROR: %d and %d are not found.\n", s1, s2);
		}
		else if (index[s1] == 0) {
			printf("ERROR: %d is not found.\n", s1);
		}
		else if (index[s2] == 0) {
			printf("ERROR: %d is not found.\n", s2);
		}
		else {
			findA(1, m, 1, m);
		}
	}
	return 0;
}