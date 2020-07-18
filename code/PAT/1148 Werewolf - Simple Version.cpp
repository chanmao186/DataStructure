#include<iostream>
using namespace std;

#define N 105
int player[N];

int main() {
	int n, w1, w2,temp;
	int wlie, mlie;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> player[i];
	}
	for (w1 = 1; w1 < n; w1++) {
		for (w2 = w1 + 1; w2 <= n; w2++) {
			wlie = mlie = 0;
			for (int i = 1; i <= n; i++) {
				if (player[i] > 0) {
					if (player[i] == w1 || player[i] == w2) {					
						if (i == w1 || i == w2) {
							wlie++;
						}
						else {
							mlie++;
						}
					}
				}
				else {
					temp = abs(player[i]);
					if (temp != w1 && temp != w2) {
						if (i == w1 || i == w2) {
							wlie++;
						}
						else {
							mlie++;
						}
					}
				}
				//if (mlie>1||wlie>1)break;
			}
			if (mlie==1&&wlie==1) {
				goto lab;
			}
		}
	}
	printf("No Solution\n");
	return 0;
	lab:printf("%d %d", w1, w2);
	return 0;
}