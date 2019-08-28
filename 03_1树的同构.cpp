
#include <iostream>
#include <vector>

using namespace std;

#define Max_Node 11
#define END -1

typedef struct node
{
	char value;
	int left;
	int right;
}Node;

void CreateTree(vector<Node>& Tree, int N)//获取树的输入，并将输入的字符合理转化成整型数字
{

	char value, left, right;
	for (int i = 0; i < N; ++i)
	{
		cin >> value >> left >> right;
		Tree[i].value = value;

		if (left == '-')
		{
			Tree[i].left = END;
		}
		else
		{
			Tree[i].left = left - '0';
		}

		if (right == '-')
		{
			Tree[i].right = END;
		}
		else
		{
			Tree[i].right = right - '0';
		}
	}
}

int FindTreeRoot(vector<Node>& Tree, int N)//寻找树的树根（树根没有其它的结点指向它）
{
	int Flag[Max_Node];
	for (int i = 0; i < N; ++i)
	{
		Flag[i] = 0;
	}

	for (int i = 0; i < N; ++i)
	{
		if (Tree[i].left != END)
		{
			Flag[Tree[i].left] = 1;
		}
		if (Tree[i].right != END)
		{
			Flag[Tree[i].right] = 1;
		}
	}

	int k;
	for (k = 0; k < N; ++k)
	{
		if (Flag[k] == 0)
		{
			break;
		}
	}
	return k;
}

bool IsOmorphic(int Root1, int Root2, vector<Node>& Tree1, vector<Node>& Tree2)//递归判断两树是否同构
{
	if (Tree1[Root1].value == Tree2[Root2].value)
	{
		//两结点相等，并都是叶子结点
		if (Tree1[Root1].left == END && Tree1[Root1].right == END && Tree2[Root2].left == END && Tree2[Root2].right == END)
		{
			return true;
		}

		//以下四种情况都是，两个结点都是有一个孩子为空，另一个子树不空且这两个孩子相等的情形
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].left].value && Tree1[Root1].right == END && Tree2[Root2].right == END)
		{
			return IsOmorphic(Tree1[Root1].left, Tree2[Root2].left, Tree1, Tree2);
		}
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].right].value && Tree1[Root1].right == END && Tree2[Root2].left == END)
		{
			return IsOmorphic(Tree1[Root1].left, Tree2[Root2].right, Tree1, Tree2);
		}
		if (Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].left].value && Tree1[Root1].left == END && Tree2[Root2].right == END)
		{
			return IsOmorphic(Tree1[Root1].right, Tree2[Root2].left, Tree1, Tree2);
		}
		if (Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].right].value && Tree1[Root1].left == END && Tree2[Root2].left == END)
		{
			return IsOmorphic(Tree1[Root1].right, Tree2[Root2].right, Tree1, Tree2);
		}

		//以下两种情形，两个结点的孩子都相等
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].left].value && Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].right].value)
		{
			return (IsOmorphic(Tree1[Root1].left, Tree2[Root2].left, Tree1, Tree2)) && (IsOmorphic(Tree1[Root1].right, Tree2[Root2].right, Tree1, Tree2));
		}
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].right].value && Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].left].value)
		{
			return (IsOmorphic(Tree1[Root1].left, Tree2[Root2].right, Tree1, Tree2)) && (IsOmorphic(Tree1[Root1].right, Tree2[Root2].left, Tree1, Tree2));
		}
	}
	//不符合以上7种情况的其它情况都说明这两棵树不同构
	return false;
}

int main(int argc, const char* argv[])
{
	//Input
	int N1 = 0;
	cin >> N1;
	vector<Node> Tree1(Max_Node);
	CreateTree(Tree1, N1);
	int N2 = 0;
	cin >> N2;
	vector<Node> Tree2(Max_Node);
	CreateTree(Tree2, N2);


	if (N1 != N2)
	{
		cout << "No";
	}
	else
	{
		if (N1 == 0)
		{
			cout << "Yes";
		}
		else
		{


			//Build Tree
			int root1 = FindTreeRoot(Tree1, N1);
			int root2 = FindTreeRoot(Tree2, N2);

			//Judge
			if (IsOmorphic(root1, root2, Tree1, Tree2))
			{
				cout << "Yes";
			}
			else
			{
				cout << "No";
			}
		}

	}
	return 0;
}
