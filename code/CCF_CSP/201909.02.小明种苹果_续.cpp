#include<iostream>
using namespace std;
#define N 1000
int flag[N] = { 0 };
int main(void) {
	long Applesum;
	int n, m, _g, g,  treeSum, temp, CurrentApples, RecordNum;
	_g = g = Applesum = treeSum = 0;
	cin >> n;
	for (int i = 0, j; i < n; i++) {
		cin >> m;
		CurrentApples = RecordNum = 0;
		for (j = 0; j < m; j++) {
			cin >> temp;
			if (temp > 0) {
				if (CurrentApples > temp) {
					RecordNum++;
				}
				CurrentApples = temp;
			}
			else {
				CurrentApples -= abs(temp);
			}
		}
		//累积总果数
		Applesum += CurrentApples;
		//记录当前树是否发生落果
		flag[i] = RecordNum>0;
		if (flag[i]) {
			//记录落果的树的数量
			treeSum++;
			//当前连续落果的树
			_g++;
		}
		else {
			_g = 0;
		}

		if (_g == 3) {
			g++;
			_g = 2;
		}
	}
	if (n >= 3) {
		if (flag[0] && flag[1] && flag[n - 1]) {
			g++;
		}
		if (flag[0] && flag[n - 1] && flag[n - 2]) {
			g++;
		}
	}
	cout << Applesum << " " << treeSum << " " << g << endl;
	return 0;
}