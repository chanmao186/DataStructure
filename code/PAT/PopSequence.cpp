#include<iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int m, n, k,cur,j;
	cin >> m >> n >> k;
	
	
	while (k--)
	{
		stack<int>s;
		vector<int> v(n + 1);
		//输入一个新的数组
		for (j = 1; j <= n; j++)
			cin >> v[j];
		cur = 1;
		for (j = 1; j <= n; j++) {
			s.push(j);
			if (s.size() > m)break;
			while (!s.empty()&&s.top()==v[cur])
			{
				s.pop();
				cur++;
			}
		}
		if (cur == n + 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}