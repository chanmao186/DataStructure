#include<iostream>
using namespace std;
#define N 40
typedef TreeNode* Tree;
struct TreeNode
{
	int Weight;
	Tree Left;
	Tree Right;
};

bool flag[N] = { false };
int inOrder[N];
int PostOrder[N];
int n;
int getInPosition(int num) {
	for (int i = 0; i < N; i++) {
		if (inOrder[i] == num) {
			return i;
		}
	}
	return 0;
}

int getPostPosition(int num) {
	for (int i = 0; i < N; i++) {
		if (PostOrder[i] == num) {
			return i;
		}
	}
	return 0;
}
int getLeftNum(int pos) {
	int num = 0;
	for (int i = pos - 1; i >= 0 && !flag[i]; i--) {
		num++;
	}
	return num;
}
int getRighttNum(int pos) {
	int num = 0;
	for (int i = pos + 1; i < n && !flag[i]; i++) {
		num++;
	}
	return num;
}

Tree CreateTree(int w) {
	Tree temp = (Tree)malloc(sizeof(TreeNode));
	temp->Weight = w;
	int left, right, ipos, ppost;//��ȡ������Ů������
	ppost = getPostPosition(w);
	ipos = getInPosition(w);
	left = getLeftNum(ipos);
	right = getRighttNum(ipos);
	flag[ipos] = true;
	if (left != 0) {
		temp->Left = CreateTree(ppost - right-1);
	}
	else {
		temp->Left = NULL;
	}

	if (right != 0) {
		temp->Right = CreateTree(ppost -1);
	}
	else {
		temp->Right = NULL;
	}
}
int main() {
	int n, i;
	for (i = 0; i < n; i++) {
		cin >> PostOrder[i];
	}
	for (i = 0; i < n; i++) {
		cin >> inOrder[i];
	}
	Tree temp = CreateTree(PostOrder[n - 1]);
	return  0;
}
/*
�ܽ᣺
1.û�����⣬�����α����ͺ������������posts�Ǻ�ѽ����
2.����ǰ��ֽ������˼·����ͺܺ�д��
*/