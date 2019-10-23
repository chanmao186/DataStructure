#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

//int main()
//{
//	BinTree BST, MinP, MaxP, Tmp;
//	ElementType X;
//	int N, i;
//
//	BST = NULL;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d", &X);
//		BST = Insert(BST, X);
//	}
//	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
//	MinP = FindMin(BST);
//	MaxP = FindMax(BST);
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d", &X);
//		Tmp = Find(BST, X);
//		if (Tmp == NULL) printf("%d is not found\n", X);
//		else {
//			printf("%d is found\n", Tmp->Data);
//			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
//			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
//		}
//	}
//	scanf("%d", &N);
//	for (i = 0; i < N; i++) {
//		scanf("%d", &X);
//		BST = Delete(BST, X);
//	}
//	printf("Inorder:"); InorderTraversal(BST); printf("\n");
//
//	return 0;
//}
void PreorderTraversal(BinTree BT) {
	if (BT) {
		printf("%d ", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
void InorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		printf("%d ", BT->Data);
		InorderTraversal(BT->Right);
	}
}
BinTree Insert(BinTree BST, ElementType X) {
	if (BST) {
		if (X > BST->Data) {
			BST->Right = Insert(BST->Right, X);
		}
		else {
			BST->Left = Insert(BST->Left, X);
		}
		return BST;
	}
	else {	
		//给指针开辟地址
		BinTree BT = (BinTree)malloc(sizeof(TNode));
		BT->Data = X;
		BT->Left = NULL;
		BT->Right = NULL;
		return BT;
	}
}
BinTree Delete(BinTree BST, ElementType X) {
	if (!BST) {
		//printf("Not Found\n", X);
		return BST;
	}
	if (X == BST->Data) {	
		BinTree temp;
		if (BST->Left&&BST->Right) {			
			//在右边寻找一个最小元素
			temp = FindMin(BST->Right);
			BST->Data = temp->Data;
		    //将该最小元素删掉
			BST->Right = Delete(BST->Right, temp->Data);
		}
		else {
			temp = BST;
			if (BST->Left) {				
				BST = BST->Left;
			}
			else{
				BST = BST->Right;
			}
			free(temp);
		}		
	}
	else if (X > BST->Data) {
		BST->Right = Delete(BST->Right, X);
	}
	else if (X < BST->Data) {
		BST->Left = Delete(BST->Left, X);
	}
	return BST;
}
Position Find(BinTree BST, ElementType X) {
	//如若未找到，则返回空
	if (!BST) return BST;
	if (BST->Data == X) {
		return BST;
	}
	else  if(X>BST->Data)
	{
		return Find(BST->Right, X);
	}
	else if (X < BST->Data) {
		return Find(BST->Left, X);
	}
}
Position FindMin(BinTree BST) {
	if (BST&&BST->Left) {
		FindMin(BST->Left);
	}
	else {
		return BST;
	}
}
Position FindMax(BinTree BST) {
	if (BST&&BST->Right) {
		FindMax(BST->Right);
	}
	else {
		return BST;
	}
}
