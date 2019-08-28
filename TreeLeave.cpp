#include<iostream>
#include <queue>
using namespace std;
#define Max 10
#define Null -1
typedef struct TreeNode Tree;
struct TreeNode
{
	int Value;
	int Left;
	int Right;
}T[Max];
queue<Tree> q;
int Input(int num) {
	int i=Null;
	if (num != 0) {
		char Left, Right;
		int check[Max] = { 0 };
		for (i = 0; i < num; i++) {
			T[i].Value = i;
			cin >> Left >> Right;
			if (Left != '-') {
				T[i].Left = Left - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (Right != '-')
			{
				T[i].Right = Right - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (i = 0; i < num; i++) {
			if (check[i] != 1) {
				break;
			}
		}
	}
	return i;
}
void Display(int root) {
	if (root == Null)return;
	Tree temp;
	q.push(T[root]);
	//判断是否为第一元素
	bool isFirst = true;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.Left == Null && temp.Right==Null) {
			if (isFirst) {
				cout << temp.Value;
				isFirst = false;
			}
			else {
				cout << ' '<<temp.Value;
			}
			
		}
		else {
			if (temp.Left != Null) {
				q.push(T[temp.Left]);
			}
			if (temp.Right != Null) {
				q.push(T[temp.Right]);
			}
		}
	}
}
int main() {
	int n,root;
	cin >> n;
	root = Input(n);
	Display(root);
	return 0;
}