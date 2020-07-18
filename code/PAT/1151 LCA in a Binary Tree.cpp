#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
#define N 100005
int inorder[N];
int preorder[N];
map<int,int> ancestor;
typedef struct TreeNode* Tree;
struct TreeNode
{
	int w;
	Tree left = NULL, right = NULL;
};

Tree CreateTree(int is, int ie, int ps, int pe) {

	Tree t = (Tree)malloc(sizeof(TreeNode));
	t->left = NULL;
	t->right = NULL;
	t->w = preorder[ps];

	int i = is;
	for (; i <= ie; i++) {
		if (inorder[i] == preorder[ps])break;
	}
	if (i - 1 >= is)
		t->left = CreateTree(is, i - 1, ps + 1, ps + i - is);
	if (i + 1 <= ie)
		t->right = CreateTree(i + 1, ie, ps + 1 + i - is, pe);
	return t;
}

void GetAnce(Tree & t) {
	if (t->left != NULL) {
		ancestor[t->left->w] = t->w;
		GetAnce(t->left);
	}

	if (t->right != NULL) {
		ancestor[t->right->w] = t->w;
		GetAnce(t->right);
	}
}
int maxn = 0x7fffffff;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &inorder[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &preorder[i]);
	}
	Tree t = CreateTree(0, m - 1, 0, m - 1);
	ancestor[preorder[0]] = maxn;
	GetAnce(t);
	int n1, n2, temp, com;
	bool no1, no2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &n1, &n2);
		no1 = ancestor[n1] == 0;
		no2 = ancestor[n2] == 0;

		if (no1 && no2) {
			printf("ERROR: %d and %d are not found.\n", n1, n2);
		}
		else if (no1) {
			printf("ERROR: %d is not found.\n", n1);
		}
		else if (no2) {
			printf("ERROR: %d is not found.\n", n2);
		}
		else {
			unordered_map<int, int> san;
			temp = n1;
			while (ancestor[temp] != maxn)
			{
				temp = ancestor[temp];
				san[temp] ++;
			}
			if (san[n2]) {
				printf("%d is an ancestor of %d.\n", n2, n1);
				continue;
			}
			else {
				temp = n2;
				while (ancestor[temp] != maxn)
				{
					temp = ancestor[temp];
					if (temp == n1) {
						printf("%d is an ancestor of %d.\n", n1, n2);
						goto en;
					}
					else if (san[temp]) {
						com = temp; break;
					}
				}
			}
			printf("LCA of %d and %d is %d.\n", n1, n2, com);
		en:;
		}
	}

	return 0;
}