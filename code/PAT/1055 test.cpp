#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	string name;
	int age, net;
	node(string n, int a, int ne) {
		name = n;
		age = a;
		net = ne;
	}
};
bool cmp(node &a, node &b) {
	return a.net != b.net ? a.net > b.net:(a.age != b.age ? a.age < b.age : a.name < b.name);
}
int book[210];
int main() {
	int n, k;
	cin >> n >> k;
	vector<node> v, w;
	for (int i = 0; i < n; i++) {
		char s[10];
		int age, net;
		cin >> s >> age >> net;
		v.push_back( node( s,age,net ));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (book[v[i].age] <= 100) {
			w.push_back(v[i]);
			book[v[i].age]++;
		}
	}
	for (int i = 0; i < k; i++) {
		int cnt, m1, m2, tmpcnt;
		scanf_s("%d %d %d", &cnt, &m1, &m2);
		tmpcnt = cnt;
		printf("Case #%d:\n", i + 1);
		for (auto it : w) {
			if (m1 <= it.age && it.age <= m2) {
				printf("%s %d %d\n", it.name.c_str(), it.age, it.net);
				if (--cnt == 0) break;
			}
		}
		if (cnt == tmpcnt) printf("None\n");
	}
	return 0;
}