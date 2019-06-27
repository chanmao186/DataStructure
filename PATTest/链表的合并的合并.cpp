#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

//int main()
//{
//	List L1, L2, L;
//	L1 = Read();
//	L2 = Read();
//	L = Merge(L1, L2);
//	Print(L);
//	Print(L1);
//	Print(L2);
//	return 0;
//}
List Read() {
	int n;
	scanf("%d", &n);
	List L = (List)malloc(sizeof(Node));
	List _L = L;
	List e;
	for (int i = 0; i < n; i++) {
		e = (List)malloc(sizeof(Node));
		scanf("%d", &e->Data);
		_L->Next = e;
		_L = e;
	}
	_L->Next = NULL;
	return L;
}
void Print(List L) {
	if (L->Next) {
		L = L->Next;		
		while (L)
		{
			printf(" %d", L->Data);
			L = L->Next;
		}
		printf("\n");
	}		
	else
	{
		printf("NULL\n");
	}
}
List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(Node));
	List L11, L21, _L;
	L11 = L1->Next;
	L21 = L2->Next;
	_L = L;
	while (L11&&L21)
	{		
		if (L11->Data > L21->Data) {
			L->Next = L21;
			L21= L21->Next;
		}
		else
		{
			L->Next = L11;
			L11 = L11->Next;
		}
		L = L->Next;
	}
	if (L11) L->Next = L11;
	if (L21)L->Next = L21;
	//将原列表清空
	L1->Next = NULL;
	L2->Next = NULL;

	return _L;
}
