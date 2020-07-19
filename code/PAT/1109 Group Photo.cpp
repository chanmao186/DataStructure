#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	string name;
	int height;
};

bool cmp(Node& n1, Node& n2) {
	if (n1.height == n2.height) {
		return n1.name < n2.name;
	}
	return n1.height > n2.height;
}
Node row[10005];
vector<Node>nodes;
int main() {
	int N, K,Rows,i,rp;
	cin >> N >> K;
	Node node;
	for (int i = 0; i < N; i++) {
		cin >> node.name >> node.height;
		nodes.push_back(node);
	}
	if (N == 0) {
		return 0;
	}
	sort(nodes.begin(), nodes.end(), cmp);
	int index = 0,mid,left,right,p=1;
	Rows = N / K + N % K;
	mid = Rows  / 2;

	row[mid] = nodes[index++];
	
	while (true) {
		if (index >= N || index >= Rows)break;
		row[mid -p] = nodes[index++];
		if (index >= N || index >= Rows)break;
		row[mid + p] = nodes[index++];
		p++;
	}
	for (i=0; i < index-1; i++) {
		printf("%s ", row[i].name.c_str());
	}
	printf("%s\n", row[i].name.c_str());
	Rows = N / K;
	mid = Rows / 2;
	for(int j=1;j<K;j++){
		rp = 1;
		p = 1;
		row[mid] = nodes[index++];
		while (true) {
			if (index >= N || rp >= Rows )break;
			row[mid - p] = nodes[index++];
			rp++;
			if (index >= N || rp >= Rows)break;
			row[mid + p] = nodes[index++];
			rp++;
			p++;
		}

		for (i = 0; i < Rows-1; i++) {
			printf("%s ", row[i].name.c_str());
		}
		printf("%s\n", row[i].name.c_str());
	}

	
	return 0;
}