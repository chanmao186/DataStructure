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
	int i, j, count;	//cityΪ��ռ�����
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
�ܽ�
cin>>���뷽ʽ��ռʱ�䣬�����ĳ�scanf();
ѧ����
��ȱ������ö���
��ȱ������õݹ�
���鼯
*/