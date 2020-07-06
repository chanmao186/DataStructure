#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int  ck = 0, cnt = 0;
string Head;
struct Node {
	bool isVisit = false;
	int Weight = 0;
	vector<string>visit;
};

unordered_map <string, int> Weight;
struct Res {
	string Head;
	int Member;
	Res(string head, int Members) {
		Head = head;
		Member = Members;
	}
};

unordered_map<string, Node>nodes;
vector<Res>res;

bool CompName(const Res& n1, const Res& n2) {
	return n1.Head < n2.Head;
}

void DFS(string name) {
	if (nodes[name].isVisit) {
		return;
	}
	nodes[name].isVisit = true;
	ck += nodes[name].Weight;
	cnt++;
	if (nodes[name].Weight > nodes[Head].Weight) {
		Head = name;
	}
	for (auto x : nodes[name].visit) {
		DFS(x);
	}
}
int main() {
	int N, K;
	cin >> N >> K;
	string n1, n2;
	int t1;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2 >> t1;
		if (nodes.count(n1) == 0) {
			Node temp;
			nodes[n1] = temp;
		}
		if (nodes.count(n2) == 0) {
			Node temp;
			nodes[n2] = temp;
		}
		nodes[n1].visit.push_back(n2);
		nodes[n1].Weight += t1;
		nodes[n2].visit.push_back(n1);
		nodes[n2].Weight += t1;
	}

	for (auto n : nodes) {
		ck = cnt = 0;
		Head = n.first;
		DFS(n.first);
		if (ck/2 > K && cnt> 2) {
			res.push_back(Res(Head, cnt));
		}
	}

	sort(res.begin(), res.end(), CompName);
	cout << res.size() << endl;
	for (auto r : res) {
		cout << r.Head << " " << r.Member << endl;
	}
	///
	return 0;
}