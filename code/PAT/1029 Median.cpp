#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

queue<int> q;
int main() {
	
	int n1, n2,n,i,j;
	int num,res=0;
	cin >> n1;
	for (i = 0; i < n1; i++) {
		cin >> num;
		q.push(num);
	}
	cin >> n2;
	n = ceil((n1 + n2)/2.0);	

	for (i = 0,j=0; i < n2; i++) {
		cin >> num;
		while (!q.empty()&&num >= q.front() && j < n) {			
			j++;
			if (j == n) {
				res = q.front();
			}
			q.pop();
		}
		j++;
		if (j == n) {
			res = num;
		}
	}
	while (!q.empty()  && j < n) {
		j++;
		if (j == n) {
			res = q.front();
		}
		q.pop();
	}
	cout << res << endl;
	return 0;
}
/*
1 1
2 1 2
*/