#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define null -1
struct Tree
{
	int value;
	int left;
	int right;
};

void CreateTree(vector<Tree> &T,int N) {
	char left, right;
	for (int i = 0; i < N; i++) {
		cin >> left >> right;
		if (left == '-') {
			T[i].left = null;
		}
		else {
			T[i].left = left - '0';
		}

		if (right == '-') {
			T[i].right = null;
		}
		else {
			T[i].right = right - '0';
		}
		T[i].value = i;
	}
}

int FindRoot(vector<Tree>& T,int N) {
	int a[10] = { 0 };
	for (int i = 0; i < N; i++) {
		if (T[i].left != null) {
			a[T[i].left] = 1;
		}

		if (T[i].right != null) {
			a[T[i].right] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		if (a[i] != 1) {
			return i;
		}
	}
	return null;
}

void Output(vector<Tree>& T,int root) {
	queue<Tree> q;
	Tree temp;
	q.push(T[root]);
	int count = 0;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.left != null) {
			q.push(T[temp.left]);
		}
		if (temp.right != null) {
			q.push(T[temp.right]);
		}
		if (temp.left == null && temp.right == null) {
			if (count == 0) {
				cout << temp.value;
			}
			else
			{
				cout << ' ' << temp.value;
			}
			count++;
		}
	}
	
}

int main() {
	int n;
	cin >> n;
	vector<Tree> T(10);
	CreateTree(T, n);
	n = FindRoot(T, n);
	Output(T, n);
}