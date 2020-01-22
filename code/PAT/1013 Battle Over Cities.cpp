#include <iostream>
#include<queue>
#include<vector>
using namespace std;

#define Max 1005
int n, m, k;
vector <int> G[Max];
int city;
bool node[Max] = { false };
void bfs(int index) {
	queue <int>q;
	q.push(index);
	node[index] = true;
	int temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		for (auto x : G[temp]) {
			if (!node[x]) {
				q.push(x);
				node[x] = true;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	int c1, c2;
	int i, j, count;	//city为被占领城市
	for (i = 0; i < m; i++) {
		scanf("%d %d", &c1, &c2);
		G[c1].push_back(c2);
		G[c2].push_back(c1);
	}
	for (i = 0; i < k; i++) {
		scanf("%d", &city);
		fill(node + 1, node + n + 1, false);
		node[city] = true;
		count = 0;
		for (j = 1; j <= n; j++) {
			if (!node[j]) {
				count++;
				bfs(j);
			}
		}
		count--;
		cout << count << endl;
	}
	return 0;
}
/*
总结
cin>>输入方式很占时间，尽量改成scanf();
学会了
广度遍历：用队列
深度遍历：用递归
并查集
*/