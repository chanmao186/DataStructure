
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

void CreateTree(vector<Node>& Tree, int N)//��ȡ�������룬����������ַ�����ת������������
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

int FindTreeRoot(vector<Node>& Tree, int N)//Ѱ����������������û�������Ľ��ָ������
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

bool IsOmorphic(int Root1, int Root2, vector<Node>& Tree1, vector<Node>& Tree2)//�ݹ��ж������Ƿ�ͬ��
{
	if (Tree1[Root1].value == Tree2[Root2].value)
	{
		//�������ȣ�������Ҷ�ӽ��
		if (Tree1[Root1].left == END && Tree1[Root1].right == END && Tree2[Root2].left == END && Tree2[Root2].right == END)
		{
			return true;
		}

		//��������������ǣ�������㶼����һ������Ϊ�գ���һ������������������������ȵ�����
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

		//�����������Σ��������ĺ��Ӷ����
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].left].value && Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].right].value)
		{
			return (IsOmorphic(Tree1[Root1].left, Tree2[Root2].left, Tree1, Tree2)) && (IsOmorphic(Tree1[Root1].right, Tree2[Root2].right, Tree1, Tree2));
		}
		if (Tree1[Tree1[Root1].left].value == Tree2[Tree2[Root2].right].value && Tree1[Tree1[Root1].right].value == Tree2[Tree2[Root2].left].value)
		{
			return (IsOmorphic(Tree1[Root1].left, Tree2[Root2].right, Tree1, Tree2)) && (IsOmorphic(Tree1[Root1].right, Tree2[Root2].left, Tree1, Tree2));
		}
	}
	//����������7����������������˵������������ͬ��
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
