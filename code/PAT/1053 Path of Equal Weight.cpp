#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp_next(int& i, int& j);


struct Node
{
	int id;
	int weight;
	vector<int>next;
	void sortNext() {
		sort(next.begin(), next.end(), comp_next);
	}
};

Node Tree[105];
bool comp_next(int& i, int& j) {
	return Tree[i].weight > Tree[j].weight;
}
vector<vector<int>> res;
vector<int>cres;
int caid = 0,aid;

void opt(int i) {
	caid += Tree[i].weight;
	cres.push_back(Tree[i].weight);
	if (caid == aid&&Tree[i].next.empty()) {
		res.push_back(cres);
	}
	if (caid >= aid) {
		caid -= Tree[i].weight;
		cres.pop_back();
		return ;
	}
	for (auto next : Tree[i].next) {
		opt(next);
	}
	caid -= Tree[i].weight;
	cres.pop_back();
	
}

int main() {
	int N, M,add,temp,k,i,j;
	cin >> N >> M >> aid;
	for (i = 0; i < N; i++) {
		Tree[i].id = i;
		cin >> Tree[i].weight;
	}
	for (i = 0; i < M; i++) {
		cin >> add>>k;
		for (j = 0; j < k; j++) {
			cin >> temp;
			Tree[add].next.push_back(temp);
		}
		Tree[add].sortNext();
	}
	opt(0);

	for (auto r : res) {	
		printf("%d", r[0]);
		for (i = 1; i < r.size(); i++) {
			printf(" %d", r[i]);
		}
		printf("\n");
	}
	return 0;
}

