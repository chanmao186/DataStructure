#include<iostream>
#include<algorithm>
using namespace std;

int D[100005] = { 0 };
int N;
int MAXD = 0;
void opt(int s, int e) {
	if (s == e) {
		cout << 0 << endl;
		return;
	}
	int res1 = 0, res2,i=s;
	for (; i < e; i++) {
		res1 += D[i];
	}
	res2 = MAXD - res1;

	cout << min(res1, res2) << endl;
}

int main() {	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		MAXD += D[i];
	}
	int s, e,op;
	cin >> op;
	for (int i = 0; i < op; i++) {
		cin >> s >> e;
		if (s < e) {
			opt(s, e);
		}
		else
		{
			opt(e, s);
		}
	}
	return 0;
}