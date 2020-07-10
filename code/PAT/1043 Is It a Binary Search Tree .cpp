#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode* Tree;
vector<int> Input;
vector<int> res,post;
struct TreeNode
{
	int Weight;
	Tree Left = NULL;
	Tree Right = NULL;
};

void Insert(Tree &t, int w) {
	if (t == NULL) {
		t = (Tree)malloc(sizeof(TreeNode));
		t->Weight = w;
		t->Right = t->Left = NULL;
	}
	else {
		if (t->Weight > w) {
			Insert(t->Left, w);
		}
		else {
			Insert(t->Right, w);
		}
	}
}


void InsertM(Tree& t, int w) {
	if (t == NULL) {
		t = (Tree)malloc(sizeof(TreeNode));
		t->Weight = w;
		t->Right = t->Left = NULL;
	}
	else {
		if (t->Weight <= w) {
			InsertM(t->Left, w);
		}
		else {
			InsertM(t->Right, w);
		}
	}
}
void PreOrder(Tree &t){
	if (t == NULL)return;
	res.push_back(t->Weight);
	PreOrder(t->Left);
	PreOrder(t->Right);
}

void PreOrderMirror(Tree& t) {
	if (t == NULL)return;
	res.push_back(t->Weight);
	PreOrderMirror(t->Right);
	PreOrderMirror(t->Left);	
}

void PostOrder(Tree& t) {
	if (t == NULL)return;
	
	PostOrder(t->Left);
	PostOrder(t->Right);
	post.push_back(t->Weight);
}


int main() {
	int n,temp;
	Tree t=NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		Input.push_back(temp);
		Insert(t, temp);
	}
	PreOrder(t);
	//if (n == 0) { cout << "YES" << endl; return 0; }
	if (res == Input) {
		cout << "YES" << endl;
		PostOrder(t);
		cout << post[0];
		for (int i = 1; i < n; i++) {
			printf(" %d", post[i]);
		}
		return 0;
	}

	res.clear();
	t = NULL;
	for (auto w : Input) {
		InsertM(t, w);
	}
	PreOrder(t);

	if (res == Input) {
		cout << "YES" << endl;
		PostOrder(t);
		cout << post[0];
		for (int i = 1; i < n; i++) {
			printf(" %d", post[i]);
		}
		return 0;
	}

	cout << "NO" << endl;
	return 0;
}