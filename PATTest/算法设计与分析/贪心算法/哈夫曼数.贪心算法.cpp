#include<iostream>
#include "../�������ݽṹ/Heap.h"
// �㷨�������� / �������ݽṹ / Heap.h
using namespace std;
//�������ֵΪ10000
#define N 20

typedef struct BTNode* BT;

struct BTNode
{
	int Weight;
	BT Left;
	BT Right;
};



BT CreateBT(int Weight, BT Left, BT Right) {
	BT bt = (BT)malloc(sizeof(BTNode));
	bt->Weight = Weight;
	bt->Left = Left;
	bt->Right = Right;
	return bt;
}
int main(void) {
	MinHeap<int> mh = MinHeap<int>(N);
	return 0;
}