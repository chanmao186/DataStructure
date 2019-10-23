#include<iostream>
using namespace std;
typedef int ElementType;

void Swap(ElementType* p1, ElementType* p2) {
	ElementType temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void Bubble_Sort(ElementType A[], int N, bool SortType) {
	int flag, P,i;
	for (P = N - 1; P >= 0; P--) {
		flag = 0;
		for (i = 0; i < P; i++) {
			if (A[i] < A[i + 1]) {
				Swap(&A[i], &A[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void Insertion_Sort(ElementType A[], int N, bool SortType) {
	ElementType temp;
	int P, i;
	for (int P = 1; P < N; P++) {
		temp = A[P];
		for (i = P; i > 0 && ((A[i - 1] > temp)==SortType);i--) {
			A[i] = A[i - 1];
		}
		A[i] = temp;
	}
}

void Shell_Sort(ElementType A[], int N,bool SortType)
{ /* ϣ������ - ��Sedgewick�������� */
	int Si, D, P, i;
	ElementType Tmp;
	/* ����ֻ�г�һС�������� */
	/* ���ݹ�ʽ 4^i-3*2^i+1��� */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };

	for (Si = 0; Sedgewick[Si] >= N; Si++)
		; /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) { /* ��������*/
			Tmp = A[P];
			for (i = P; i >= D && ((A[i - D] > Tmp)==SortType); i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}

void Selection_Sort(ElementType A[], int N, bool SortType) {
	int temp,index;
	for (int i = 0,j; i < N-1; i++) {
		temp = A[i];
		index = i;
		for (j = i+1; j < N; j++) {
			if ((A[j] > temp)==SortType) {
				index = j;
			}
		}
		if (index != i) {
			Swap(&A[i], &A[index]);
		}
	}
}

void PercDown(ElementType A[], int p, int N)
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X >= A[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void Heap_Sort(ElementType A[], int N)
{ /* ������ */
	int i;

	for (i = N / 2 - 1; i >= 0; i--)/* �������� */
		PercDown(A, i, N);

	for (i = N - 1; i > 0; i--) {
		/* ɾ�����Ѷ� */
		Swap(&A[0], &A[i]); /* ������7.1 */
		PercDown(A, 0, i);
	}
}

