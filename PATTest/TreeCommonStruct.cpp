#include<iostream>
using namespace std;
#define MaxTree 10
#define Elenment char
#define TreeIndex int
#define Null -1
typedef struct TNode Tree;
struct  TNode
{
	Elenment data;
	TreeIndex Left;
	TreeIndex Right;
}T1[MaxTree],T2[MaxTree];
TreeIndex BuildTree(Tree T[])
{
	int n, root, i=Null;
	char Left, Right;
	cin >> n;
	if (n) {
		int check[MaxTree] = { 0 };
		for (i = 0; i < n; i++) {
			cin >> T[i].data >> Left >> Right;
			if (Left != '-') {
				T[i].Left = Left - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (Right != '-') {
				T[i].Right = Right - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (i = 0; i < n; i++) {
			if (check[i] != 1)
				break;
		}
	}
	root = i;
	return root;
};
bool ismorphic(TreeIndex R1, TreeIndex R2) {
	if ((R1 == Null) && (R2 == Null))
		return true;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return false;	 //其中一个为空另一个不为空
	Tree t1=T1[R1], t2=T2[R2];
	if(t1.data!=t2.data)
		return false;	//两个节点的值不相等
	if (t1.Left == Null && t2.Left == Null)
		return ismorphic(t1.Right, t2.Right);
	if (((t1.Left != Null) && (t2.Left != Null)) && (T1[t1.Left].data == T2[t2.Left].data)) {
		return ismorphic(t1.Left, t2.Left) && ismorphic(t1.Right, t2.Right);
	}
	else {
		return 	ismorphic(t1.Left, t2.Right) && ismorphic(t1.Right, t2.Left);
	}
}
int main() {
	TreeIndex r1, r2;
	r1 = BuildTree(T1);
	r2 = BuildTree(T2);
	if (ismorphic(r1, r2))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}