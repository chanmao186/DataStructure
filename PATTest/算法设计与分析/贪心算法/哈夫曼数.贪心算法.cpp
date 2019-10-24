#include<iostream>
using namespace std;
//定义最大值为10000
#define MAX 10000

typedef struct BTNode* BT;

struct BTNode
{
	int Weight;
	BT Left;
	BT Right;
};



BT CreateBT(float Weight, BT Left, BT Right) {
	BT bt = (BT)malloc(sizeof(BTNode));
	bt->Weight = Weight;
	bt->Left = Left;
	bt->Right = Right;
	return bt;
}
int main(void) {
	return 0;
}