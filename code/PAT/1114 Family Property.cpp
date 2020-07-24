#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int id, fathe, mother;
	int es, esn;
	vector<int>Child;
};
Node nodes[10000];
int vist[10000] = { 0 };
vector<int>family;
int es, esn, num, ids;
void opt(int id) {
	if (id == -1 || vist[id] == 2)return;
	if (ids > id) {
		ids = id;
	}
	if (vist[id] == 0) {
		vist[id] = 2;
		num++;
		return;
	}
	vist[id] = 2;
	num++;
	es += nodes[id].es;
	esn += nodes[id].esn;
	for (auto& i : nodes[id].Child) {
		opt(i);
	}
	opt(nodes[id].fathe);
	opt(nodes[id].mother);
}
int main() {
	int N, index, cn, c;
	cin >> N;
	for (int i = 0, j; i < N; i++) {
		cin >> index;
		nodes[index].id = index;
		cin >> nodes[index].fathe >> nodes[index].mother >> cn;
		for (j = 0; j < cn; j++) {
			cin >> c;
			nodes[index].Child.push_back(c);
		}
		nodes[index].es = 0;
		cin >> nodes[index].esn >> nodes[index].es;
		family.push_back(index);
		vist[index] =1;
	}

	printf("%d\n", family.size());
	for (auto& i : family) {
		if (vist[i] != 1)continue;
		es = esn = num = 0;
		ids = 10000;
		opt(i);
		printf("%04d %d %.3f %.3f\n", ids, num, esn * 1.0 / num, es * 1.0 / num);
	}
	return 0;
}