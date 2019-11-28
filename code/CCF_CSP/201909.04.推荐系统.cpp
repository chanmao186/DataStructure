#include<iostream>
using namespace std;
typedef struct ItemNode* Item;

#define MAX 2000000000
struct ItemNode {
	int ID;
	int Value;
	ItemNode(int i, int v, Item n) :ID(i), Value(v), Next(n) {};
	bool operator<(const Item& t) {
		return this->Value < t->Value;
	}
	Item Next;
};

Item CreateItem(int ID, int Value, Item Next) {
	Item temp = (Item)malloc(sizeof(ItemNode));
	temp->ID = ID;
	temp->Value = Value;
	temp->Next = Next;
	return temp;
}

struct ItemType
{
	int ID;
	Item Head;
	ItemType(int i) :ID(i) {
		Head = CreateItem(0, MAX, NULL);
	};
	void Insert(int ID, int Value) {
		Item temp = CreateItem(ID, Value, NULL);
		Item h = Head;
		while (h->Next && h->Next > temp)
		{
			h = h->Next;
		}
		temp->Next = h->Next;
		h->Next = temp;
	}

	void Delete(int ID) {
		Item  h = Head,temp;
		while (h->Next)
		{
			if (h->Next->ID == ID) {

				temp = h->Next;
				h->Next = temp->Next;
				free(temp);
				break;
			}
			h = h->Next;
		}
	}

	void Seek(int n) {
		 
	}
};

int main() {
	int m, n, op, i, j, ID, Value;
	cin >> m >> n;

	for (i = 0; i < n; i++) {
		cin >> ID >> Value;
		for (j = 0; j < m; j++) {

		}
	}

	//ÊäÈë²Ù×÷Êý
	cin >> op;
	for (i = 0; i < op; i++) {

	}
	return 0;
}