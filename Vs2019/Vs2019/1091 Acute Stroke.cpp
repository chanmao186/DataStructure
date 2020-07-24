#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int core[65][1300][130] = { 0 };
bool vist[65][1300][130] = { false };
int L,M, N, T,temp;
struct Node { 
	int x, y, z;
	Node(){}
	Node(int i, int j, int k) {
		x = i, y = j, z = k;
	}
};
bool Check(int i, int j, int k) {
	if (i >= L || j >= M || k >= N || i < 0 || j < 0 || k < 0 ||vist[i][j][k] || core[i][j][k] == 0) {
		return false;
	}
	return true;
}

void BFS(int i, int j, int k) {
	if (vist[i][j][k]|| core[i][j][k]==0) {
		return;
	}
	vist[i][j][k] = true;
	Node node(i, j, k);
	queue<Node>q;
	q.push(node);
	while (!q.empty())
	{
		node = q.front();
		
		q.pop();
		temp++;
		if (Check(node.x-1, node.y, node.z)) {
			q.push(Node(node.x-1, node.y, node.z));
			vist[node.x-1][node.y][node.z] = true;
		}
		if (Check(node.x+1, node.y, node.z)) {
			q.push(Node(node.x+1, node.y, node.z));
			vist[node.x+1][node.y][node.z] = true;
		}

		if (Check(node.x, node.y-1, node.z)) {
			q.push(Node(node.x, node.y-1, node.z));
			vist[node.x][node.y-1][node.z] = true;
		}
		if (Check(node.x, node.y+1, node.z)) {
			q.push(Node(node.x, node.y+1, node.z));
			vist[node.x][node.y+1][node.z] = true;
		}

		if (Check(node.x, node.y, node.z-1)) {
			q.push(Node(node.x, node.y, node.z-1));
			vist[node.x][node.y][node.z-1] = true;
		}
		if (Check(node.x, node.y, node.z+1)) {
			q.push(Node(node.x, node.y, node.z+1));
			vist[node.x][node.y][node.z+1] = true;
		}
	}
}

int main() {
	cin >> M >> N >> L>>T;
	int i, j, k,val;
	i = j = k = val = 0;
	for (; i < L; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &core[i][j][k]);
			}
		}
	}

	for (i=0; i < L; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < N; k++) {			
				if (!vist[i][j][k]&&core[i][j][k]) {
					temp = 0;
					BFS(i, j, k);
					if (temp >= T) {
						val += temp;
					}				
				}			
			}
		}
	}
	cout << val << endl;
	return 0;
}