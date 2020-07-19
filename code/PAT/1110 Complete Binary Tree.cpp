#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct TreeNode* Tree;
struct TreeNode
{
	int w;
	Tree left, right;
};

Tree trees[25];
bool vist[25] = { false };
int ance[25];
int N, v, root;

int main() {
	fill(ance, ance + 25, -1);
	v = 0;
	int temp;
	cin >> N;
	string left, right;
	Tree t;

	for (int i = 0; i < 25; i++) {
		trees[i] = (Tree)malloc(sizeof(TreeNode));
	}
	for (int i = 0; i < N; i++) {
		cin >> left >> right;

		trees[i]->w = i;
		if (left == "-") {
			trees[i]->left = NULL;
		}
		else {
			temp = atoi(left.c_str());
			if (temp >= 20) {
				trees[i]->left = NULL;
			}
			else {
				trees[i]->left = trees[temp];
				ance[temp] = i;
			}

		}
		if (right == "-") {
			trees[i]->right = NULL;
		}
		else {
			temp = atoi(right.c_str());
			if (temp >= 20) {
				trees[i]->right = NULL;
			}
			else {
				trees[i]->right = trees[temp];
				ance[temp] = i;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (ance[i] == -1) {
			root = i; break;
		}
	}

	queue<Tree> q;
	q.push(trees[root]);
	while (true)
	{
		t = q.front();
		q.push(t->left);
		q.push(t->right);
		q.pop();
		if (q.front() == NULL) {
			q.pop();
			while (!q.empty())
			{
				if (q.front() != NULL) {
					printf("NO %d", root);
					return 0;
				}
				q.pop();
			}
			printf("YES %d", t->w);
			return 0;
		}
    			
	}
	return 0;
}