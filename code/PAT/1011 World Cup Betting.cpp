#include<iostream>
using namespace std;
int main() {
	double peilv;
	double ans=1,temp;
	int index;
	char flag[3] = { 'W','T','L' };
	for (int i = 0,j; i < 3; i++) {
		temp = 0;
		for (j = 0; j < 3; j++) {			
			cin >> peilv;
			if (peilv > temp) {
				temp = peilv;
				index =j;
			}					
		}		
		ans *= temp;
		cout << flag[index] << " ";
	}
	ans = (ans * 0.65 - 1) * 2;
	printf("%.2f\n", ans);
	return 0;
}