#include<iostream>
using namespace std;
int num[3][3];
int main() {
	scanf("%d.%d.%d", &num[0][0], &num[0][1], &num[0][2]);
	scanf("%d.%d.%d", &num[1][0], &num[1][1], &num[1][2]);

	for (int i = 0; i < 3; i++) {
		num[2][i] = num[0][i] + num[1][i];
	}

	num[2][1] += num[2][2] / 29;
	num[2][2] %= 29;

	num[2][0] += num[2][2] / 17;
	num[2][1] %= 17;
	//num[2][0] = num[2][0] > 10000000 ? 10000000 : num[2][0];
	num[2][0] %= 10000001;

	printf("%d.%d.%d", num[2][0], num[2][1], num[2][2]);
	return 0;
}