#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N 40
typedef struct TreeNode* Tree;
struct TreeNode
{
	int Weight;
	Tree Left;
	Tree Right;
};
vector<int> result;
bool flag[N] = { false };
int inOrder[N];
int PostOrder[N];
int n;

int GetPosInInOrder(int s, int e,int value) {
	int mid;
	for (mid = s; mid < e; mid++) {
		if (inOrder[mid] == value) {
			return mid;
		}
	}
	return -1;
}

//创建一个树
//ps先序的开始位置
Tree CreateTree(int ps, int pe, int is, int ie) {
	if (pe == ps)return NULL;
	Tree tree = (Tree)malloc(sizeof(TreeNode));
	tree->Weight = PostOrder[pe - 1];
	int mid = GetPosInInOrder(is, ie, tree->Weight);
	tree->Left = CreateTree(ps, ps + (mid - is), is, mid);
	tree->Right = CreateTree(ps + (mid - is), pe - 1, mid + 1, ie);
	return tree;
}

void OutPut(Tree tree) {
	queue<Tree> tq;
	tq.push(tree);
	while (!tq.empty())
	{
		tree = tq.front();
		result.push_back(tree->Weight);
		if (tree->Left != NULL) {
			tq.push(tree->Left);
		}
		if (tree->Right != NULL) {
			tq.push(tree->Right);
		}
		tq.pop();
	}

	if (result.size() > 0) {
		cout << result[0];
	}

	for (int i = 1; i < result.size(); i++) {
		cout << " " << result[i];
	}
}
int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> PostOrder[i];
	}
	for (i = 0; i < n; i++) {
		cin >> inOrder[i];
	}
	Tree tree = CreateTree(0, n, 0, n);
	OutPut(tree);
	return  0;
}
/*
总结：
1.没读好题，分清层次遍历和后序中序遍历，posts是后呀！！
2.做题前在纸上理清思路后面就很好写了
案例：
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

*/