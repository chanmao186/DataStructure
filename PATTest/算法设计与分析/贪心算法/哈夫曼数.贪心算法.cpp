#include<iostream>
using namespace std;

#define N 50
#define Max 100
#define Min -100
typedef struct HuffmanNode* Huffman;
typedef struct BTNode* BT;
typedef struct MinHeapNode* MinHeap;
typedef struct HuffmanArrayNode* HuffmanArray;
BT _CreateBT(int Weight, BT Left, BT Right);
void PercDown(MinHeap heap, int p);
MinHeap CreateMinHeap(int Maxsize);
bool InsertToMinHeap(MinHeap h, BT bt);
BT DeleteInMinHeap(MinHeap h);
MinHeap BuildMinHeap(string s);
BT CreateBT(char s, int Weight, BT Left, BT Right);
void PercDown(MinHeap heap, int i);
struct HuffmanNode
{
	char s;
	char code[N];
	int n;
};

struct BTNode
{
	char c;
	int Weight;
	BT Left;
	BT Right;
};

struct MinHeapNode {
	BT* Date;
	int size;
	int capacity;
};

struct HuffmanArrayNode
{
	Huffman* hfarry;
	int size;
};

BT _CreateBT(int Weight, BT Left, BT Right) {
	BT bt = (BT)malloc(sizeof(BTNode));
	bt->Weight = Weight;
	bt->Left = Left;
	bt->Right = Right;
	bt->c = '0';
	return bt;
}
MinHeap CreateMinHeap(int Maxsize) {

	MinHeap H = (MinHeap)malloc(sizeof(MinHeapNode));
	H->Date = (BT*)malloc((Maxsize + 1) * sizeof(BT));
	H->Date[0] = _CreateBT(-100, NULL, NULL);
	for (int i = 1; i < Maxsize + 1; i++) {
		H->Date[i] = NULL;
	}
	H->size = 0;
	H->capacity = Maxsize + 1;
	return H;
}
/*
向小顶堆中插入数据
h规定的小顶堆
bt要插入的树节点
*/
bool InsertToMinHeap(MinHeap h, BT bt) {
	//检测堆是否已满
	if (h->size == h->capacity)return false;
	int i = ++h->size;
	for (; bt->Weight < h->Date[i / 2]->Weight; i /= 2) {
		h->Date[i] = h->Date[i / 2];
	}
	h->Date[i] = bt;
	return true;
}

BT DeleteInMinHeap(MinHeap h) {
	if (h->size == 0)return NULL;
	BT item = h->Date[1],
		temp = h->Date[h->size--];
	int parent, chlid;
	parent = 1;
	for (; parent*2 < h->size; parent = chlid) {
		chlid = parent * 2;
		if (h->Date[chlid + 1]->Weight < h->Date[chlid]->Weight) {
			chlid++;
		}
		if (temp->Weight < h->Date[chlid]->Weight)break;
		h->Date[parent] = h->Date[chlid];
	}
	h->Date[parent] = temp;

	return item;
}
/*
根据提供的数组建立一个小顶堆
*/
MinHeap BuildMinHeap(string s) {
	MinHeap heap = CreateMinHeap(Max);
	int i = 0, j = 0;
	for (; i < s.length(); i++) {

		for (j = 1; heap->Date[j]; j++) {
			if (heap->Date[j]->c == s[i]) {
				heap->Date[j]->Weight++;
				break;
			}
		}
		if (!heap->Date[j]) {
			heap->size++;
			heap->Date[j] = CreateBT(s[i], 1, NULL, NULL);
		}
	}

	cout << "各字符出现的次数为:" << endl;
	for (i = 1; i <= heap->size; i++) {
		cout << heap->Date[i]->c << "  出现" << heap->Date[i]->Weight <<"次" << endl;
	}
	for (i = heap->size / 2; i > 0; i--) {
		PercDown(heap, i);
	}
	return heap;
}
void PercDown(MinHeap heap, int p) {
	BT temp = heap->Date[p];
	int parent, chlid;
	for (parent = p; parent * 2 <= heap->size; parent = chlid) {
		chlid = parent * 2;
		if (chlid < heap->size && (heap->Date[chlid + 1]->Weight < heap->Date[chlid]->Weight)) {
			chlid++;
		}
		if (temp->Weight < heap->Date[chlid]->Weight) {
			break;
		}
		else {
			heap->Date[parent] = heap->Date[chlid];
		}
	}
	heap->Date[parent] = temp;
}
BT CreateBT(char s, int Weight, BT Left, BT Right) {
	BT bt = _CreateBT(Weight, Left, Right);
	bt->c = s;
	return bt;
}

Huffman CreateHuffman(char s,Huffman hfm) {
	Huffman hf = (Huffman)malloc(sizeof(HuffmanNode));
	for (int i = 0; i < hfm->n; i++) {
		hf->code[i] = hfm->code[i];
	}	
	hf->n = hfm->n;
	hf->s = s;
	return hf;
}

HuffmanArray CreateHuffmanArray(int n) {
	HuffmanArray hfma = (HuffmanArray)malloc(sizeof(HuffmanArrayNode));
	hfma->hfarry = (Huffman*)malloc(n*sizeof(HuffmanArray));
	hfma->size = 0;
	return hfma;
}

void WirteHuffmanArray(BT bt,HuffmanArray hfma,Huffman hfm) {
	if (!bt)return;
	//哈佛曼树的节点的度数为2，所以只要没有左子树就是叶子节点
	if ((!bt->Left)) {
		hfma->hfarry[hfma->size++] = CreateHuffman(bt->c, hfm);
		return;
	}

	hfm->code[hfm->n++] = '0';
	WirteHuffmanArray(bt->Left, hfma,hfm);
	hfm->code[hfm->n - 1] = '1';
	WirteHuffmanArray(bt->Right, hfma, hfm);
	hfm->n--;
}

int main(void) {
	string s;
	cout << "请输入一个字符串:" << endl;
	cin >> s;
	//防止输入空数字
	if (s.length() <1)return 0;

	MinHeap heap= BuildMinHeap(s);
	BT left, right, temp;


	while (heap->size>1)  {
		left = DeleteInMinHeap(heap);
		right = DeleteInMinHeap(heap);
		temp = _CreateBT(left->Weight + right->Weight, left, right);
		InsertToMinHeap(heap, temp);
	}
	temp = DeleteInMinHeap(heap);

	Huffman hfm = (Huffman)malloc(sizeof(HuffmanNode));
	hfm->n = 0;
	HuffmanArray hfma = CreateHuffmanArray(N);
	WirteHuffmanArray(temp, hfma, hfm);
	for (int i = 0,j; i < hfma->size; i++) {
		cout << hfma->hfarry[i]->s << "  ";
		for(j=0;j< hfma->hfarry[i]->n;j++){
			cout << hfma->hfarry[i]->code[j];
		}
		cout << endl;
	}
	return 0;
}