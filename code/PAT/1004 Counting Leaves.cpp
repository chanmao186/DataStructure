#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> node[105];

queue<int> q;
int main() {
	int N, M;
	cin >> N >> M;
	if (N == 0) {
		return 0;
	}
	int i, id, chil,chil_num;
	for (i = 0; i < M; i++) {
		cin >> id >> chil_num;
		while (chil_num--) {
			cin >> chil;
			node[id].push_back(chil);
		}
	}
	
	if (N == 1) {
		cout << "1" << endl;
		return 0;
	}
	cout << "0";
	for (auto x : node[1]) {
		q.push(x);
	}
	int l = q.size(), leaf;
	int index;
	while (l)
	{
		leaf = 0;
		for (i = 0; i < l; i++) {
			index = q.front();
			if (node[index].size()) {

				for (auto x : node[index]) {
					q.push(x);
				}
			}
			else {
				leaf++;
			}
			q.pop();
		 }
		cout << " " << leaf;
		l = q.size();
	}
	return 0;
}