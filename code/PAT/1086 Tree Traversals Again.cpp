#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
struct Tree {
	int left, right;
};
Tree trees[105];
vector<int>res;
void Post(int i) {
	if (i == -1)return;
	Post(trees[i].left);
	Post(trees[i].right);
	res.push_back(i);
}

int main() {
	Tree t;
	t.left = -1;
	t.right = -1;
	fill(trees, trees + 105, t);

	stack<int>s;
	string op;
	int w, opi, n, head;	
	bool isInsertRight = false;

	cin >> n;
	cin >> op >> head;
	opi = head;
	s.push(opi);
	for (int i = 1;!s.empty()|| i < n;) {
		cin >> op;
		if (op == "Pop") {
			opi = s.top();
			s.pop();
			isInsertRight = true;
		}
		else {
			cin >> w;
			s.push(w);
			if (isInsertRight) {
				trees[opi].right = w;
				isInsertRight = false;
				//≤Â»Î”“
			}
			else {
				trees[opi].left = w;
			}
			opi = w;
			i++;
		}
	}

	Post(head);
	printf("%d", res[0]);

	for (int i = 1; i < res.size(); i++) {
		printf(" %d", res[i]);
	}

	return 0;
}