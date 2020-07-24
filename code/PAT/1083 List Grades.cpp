#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct  Node
{
	string name, id;
	int grade;
};

vector<Node>Orgi, res;

bool cmp(Node &n1,Node &n2){
	return n1.grade > n2.grade;
}

int main() {
	Node node;
	int n,g1,g2,temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node.name >> node.id >> node.grade;
		Orgi.push_back(node);
	}

	sort(Orgi.begin(), Orgi.end(), cmp);
	cin >> g1 >> g2;
	
	for (auto& n : Orgi) {
		if (n.grade <= g2 && n.grade >= g1) {
			res.push_back(n);
		}
	}

	if (res.size() == 0) {
		printf("NONE");
		return 0;
	}

	for (auto& n : res) {
		printf("%s %s\n", n.name.c_str(), n.id.c_str());
	}

	return 0;
}