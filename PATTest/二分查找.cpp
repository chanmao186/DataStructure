#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch(List L, ElementType X);

//int main()
//{
//	List L;
//	ElementType X;
//	Position P;
//
//	L = ReadInput();
//	scanf("%d", &X);
//	P = BinarySearch(L, X);
//	printf("%d\n", P);
//
//	return 0;
//}

List ReadInput() {
	List L = (List)malloc(sizeof(LNode));
	int n;
	L->Data[0] = 100000;
	scanf("%d", &n);
	if (n > 10)n = 10;
	for (int i = 1; i < n; i++) {
		scanf("%d", &L->Data[i]);
	}
	L->Last = n;
	return L;
}
/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch(List L, ElementType X) {
	Position p, l, cp;
	p = 1;
	l = L->Last;
	int mid;
	while (p<=l)
	{
		cp = (p + l) / 2;
		mid = L->Data[cp];
		if (X == mid) return cp;
		else if (X > mid) p = cp + 1;
		else  l = cp - 1;
	}
	return NotFound;
}