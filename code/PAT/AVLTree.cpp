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
更新树的高度
*/
AVLTree UpdateHeight(AVLTree Tree) {
	Tree->Height = Max(GetHeight(Tree->Left), GetHeight(Tree->Right)) + 1;
}

int GetHeight(AVLTree tree) {
	if (!tree)return -1;
	return tree->Height;
}

/*
左旋转
*/
AVLTree LeftRotation(AVLTree A)
{ /* 注意：A必须有一个左子结点B */
  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	UpdateHeight(A);
	UpdateHeight(B);
	return B;
}

/*
右旋转
*/
AVLTree RightRotation(AVLTree A)
{ /* 注意：A必须有一个右子结点B */
  /* 将A与B做右单旋，更新A与B的高度，返回新的根结点B */
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	UpdateHeight(A);
	UpdateHeight(B);
	return B;
}
/*
注意：A必须有一个左子结点B，且B必须有一个右子结点C 
将A、B与C做两次单旋，返回新的根结点C 
针对情况:破坏平衡的节点在左子树的右边
*/
AVLTree LeftRightRotation(AVLTree A) {
	A->Left = RightRotation(A->Left);
	return LeftRotation(A);
}
/*
同左右旋转
*/
AVLTree RightLeftRotation(AVLTree A) {
	A->Right = LeftRotation(A->Right);
	return LeftRotation(A);
}
/*
向AVL数中插入一个数据
Date要插入的数据
return 插入后AVL树的头结点
注：若Date已经在该树里的话，则不进行任何修改
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