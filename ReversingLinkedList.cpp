#include<iostream>
#include <iomanip>
using namespace std;
typedef struct LNode* List;
struct LNode
{
	int Address;
	int Data;
	int NextAddress;
	List Next;
};

List ReadList(int n) {
	List L, temp, Node;
	L = (List)malloc(sizeof(LNode));
	temp = L;
	while (n--)
	{
		Node = (List)malloc(sizeof(LNode));
		cin >> Node->Address >> Node->Data >> Node->NextAddress;
		temp->Next = Node;
		temp = Node;
	}
	//使尾节点为NULL;
	temp->Next = NULL;
	return L;
}

List SeekNode(List L, int Address) {
	if (!L||Address==-1) return NULL;
	List temp;
	temp = L->Next;
	while (temp)
	{
		if (temp->Address == Address) {
			L->Next = temp->Next;
			temp->Next = NULL;
			return temp;
		}
		L = temp;
		temp = temp->Next;
	}
	return NULL;
}


List ListTrim(List L, int FirstAddress) {
	List temp, L1, _L;
	_L = L;
	L1 = (List)malloc(sizeof(LNode));
	temp = L1;
	temp->Next = SeekNode(L, FirstAddress);
	while (temp->Next)
	{
		temp = temp->Next;
		temp->Next = SeekNode(L, temp->NextAddress);
	}
	return L1;
}

List ReverList(List L, int k) {
	if (!L || !L->Next)return NULL;
	List temp, Last, Next, Tail, LastTail;
	temp = L->Next;
	int n = 0;
	//计算实际的节点个数
	while (temp)
	{
		temp = temp->Next;
		n++;
	}
	Next = NULL;
	LastTail = L;
	temp = L->Next;
	Tail = temp;

	for (int i, j = 0; k&&j < n / k; j++) {
		Tail = temp;
		Last = temp;
		temp = temp->Next;				
		for (i = 1; i < k&&temp; i++) {
			Next = temp->Next;
			temp->Next = Last;
			temp->NextAddress = Last->Address;
			//进行错位后移
			Last = temp;
			temp = Next;
		}
		LastTail->Next = Last;
		LastTail->NextAddress = Last->Address;
		LastTail = Tail;
	}
	if (temp) {
		LastTail->Next = temp;
		LastTail->NextAddress = temp->Address;
	}
	else
	{
		LastTail->Next = NULL;
		LastTail->NextAddress = -1;
	}
	return L;
}
void DisplayList(List L) {
	if (!L)return;
	L = L->Next;
	while (L)
	{
		if (L->NextAddress == -1)
			printf("%05d %d %d\n", L->Address, L->Data, L->NextAddress);
		else
			printf("%05d %d %05d\n", L->Address, L->Data, L->NextAddress);
		L = L->Next;
	}
}
int main() {
	List L1, L2, L3;
	int firstAddress, n, k;
	cin >> firstAddress >> n >> k;

	L1 = ReadList(n);
	L2 = ListTrim(L1, firstAddress);
	L3 = ReverList(L2, k);
	DisplayList(L3);
	return 0;
}
