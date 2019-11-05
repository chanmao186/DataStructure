#include <iostream>
using namespace std;
typedef struct AVLTreeNode* AVLTree;
struct AVLTreeNode {
	int Date;
	int Height;
	AVLTree Left;
	AVLTree Right;
};
int Max(int a, int b) {
	return a > b ? a : b;
}

AVLTree CreateAVLTree(int Date, AVLTree Left, AVLTree Right) {
	AVLTree T = (AVLTree)malloc(sizeof(AVLTreeNode));
	T->Height = 0;
	T->Date = Date;
	T->Left = Left;
	T->Right = Right;
}

/*
�������ĸ߶�
*/
AVLTree UpdateHeight(AVLTree Tree) {
	Tree->Height = Max(GetHeight(Tree->Left), GetHeight(Tree->Right)) + 1;
}

int GetHeight(AVLTree tree) {
	if (!tree)return -1;
	return tree->Height;
}

/*
����ת
*/
AVLTree LeftRotation(AVLTree A)
{ /* ע�⣺A������һ�����ӽ��B */
  /* ��A��B������������A��B�ĸ߶ȣ������µĸ����B */
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	UpdateHeight(A);
	UpdateHeight(B);
	return B;
}

/*
����ת
*/
AVLTree RightRotation(AVLTree A)
{ /* ע�⣺A������һ�����ӽ��B */
  /* ��A��B���ҵ���������A��B�ĸ߶ȣ������µĸ����B */
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	UpdateHeight(A);
	UpdateHeight(B);
	return B;
}
/*
ע�⣺A������һ�����ӽ��B����B������һ�����ӽ��C 
��A��B��C�����ε����������µĸ����C 
������:�ƻ�ƽ��Ľڵ������������ұ�
*/
AVLTree LeftRightRotation(AVLTree A) {
	A->Left = RightRotation(A->Left);
	return LeftRotation(A);
}
/*
ͬ������ת
*/
AVLTree RightLeftRotation(AVLTree A) {
	A->Right = LeftRotation(A->Right);
	return LeftRotation(A);
}
/*
��AVL���в���һ������
DateҪ���������
return �����AVL����ͷ���
ע����Date�Ѿ��ڸ�����Ļ����򲻽����κ��޸�
*/
AVLTree Insert(AVLTree T,int Date) {
	
	if (!T) {
		T = CreateAVLTree(Date, NULL, NULL);
	}
	else if (Date < T->Date) {
		T->Left = Insert(T->Left, Date);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (Date < T->Left->Date) {
				T = LeftRotation(T);
			}
			else {
				T = LeftRightRotation(T);
			}
		}
	}
	else if (Date > T->Date) {
		if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
			if (Date > T->Right->Date) {
				RightRotation(T);
			}
			else {
				RightLeftRotation(T);
			}
		}		
	}
	UpdateHeight(T);
	return T;
}