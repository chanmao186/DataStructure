#include<iostream>
//�����ļ������õ�ͷ�ļ������԰��������и���
#include"../�������ݽṹ/Heap.h"
#include <algorithm>
#include <vector>
using namespace std;
#define N 100
void AddLiveNode(int up, int cp, int cw, int ch, int lev);

//��Ʒ�Ľṹ��
struct Item {
	int ID;//ID��ţ�����Ʒ���±꣬��Ϊ֮��Ҫ������������Ҫ���±��¼
	int Weight;//����
	int Value;//��ֵ
	float d;//��λ��ֵ
	Item() {};
	Item(int id, int weight, int value) :ID(id), Weight(weight), Value(value) {
		d = Value / (Weight * 1.0);
	}
	//����Ԥ�����֮������ʹ�ã���Ϊ���������Է��ص��Ǵ��ں�
	bool operator <(const Item& other)const {
		return d > other.d;
	}
};

//����ѡ�����Ϣ
struct bbNode {
	bbNode* parent;
	int flag;
	bbNode(bbNode* p, int f) :parent(p), flag(f) {}
};

/*
���еĽڵ㣬�����ܻ�����ֵ��������
*/
struct HeapNode {

	bool operator <(const HeapNode& h) const {
		return uprofit < h.uprofit;
	}
	HeapNode() {};
	void operator = (int Num) {
		uprofit = Num;
	}
	int uprofit;//���ܴﵽ������ֵ
	int profit;//��ǰ��ֵ
	int Weight;//��ǰ����
	int Level;//��ǰ����Ĳ��
	bbNode* ptr;//��Ʒѡ����Ϣ��ָ��
	HeapNode(int up, int cp, int w, int lev, bbNode* b) :
		uprofit(up), profit(cp), Weight(w), Level(lev), ptr(b) {}
};


int BestX[N] = { 0 };//���Ž�����
/*
cw:��ǰ����
cp:��ǰ��ֵ
n:��Ʒ����
c:��������
up����·�����ܴﵽ�����ֵ
besp�����Ż���
*/
int cw, cp, n, c, up, bestp;
/*
��Ʒ����
*/
Item items[N];
//������¼�����Ľڵ�
HeapNode HN;
//ѡ����Ϣ�ĸ��ڵ�
bbNode* E = NULL;
//ѡ����Ϣ�����Žڵ�
bbNode* BestE = NULL;
//�����󶥶�
MaxHeap<HeapNode> H(1000);

/**
�޽纯��������̰���㷨�󱳰������н�
*/
int Bound(int i) {
	int cleft = c - cw,
		b = cp;
	for (; i < n && cleft>items[i].Weight; i++) {
		cleft -= items[i].Weight;
		b += items[i].Value;
	}
	//������ʣ����Ʒ����ʣ����Ʒ�Ĳ���װ������
	if (i <= n) {
		b += items[i].d * cleft;
	}
	return b;
}
int main() {
	
	//��ʼ��
	cw = cp = up = bestp = 0;
	//��������
	cout << "�����뱳���ĳ��أ�" << endl;
	cin >> c;
	cout << "��������Ʒ��������" << endl;
	cin >> n;
	cout << "�밴˳��������Ʒ�������ͼ�ֵ��" << endl;
	int w, v, i,lev;

	for (i = 0; i < n; i++) {
		cin >> w >> v;
		items[i] = Item(i, w, v);
	}
	//������Ʒ�ļ�ֵ��������
	sort(items, items + n);

	//��0����Դﵽ�����ֵ
	up = Bound(0);
	i = 0;
	while (i < n)
	{
		//����ѡ�����Ʒ�ļ�ֵ
		w = cw + items[i].Weight;
		if (w < c) {
			v = cp + items[i].Value;
			if (v > bestp) {
				bestp = v;
			}
			//���ýڵ�����ڵ�
			AddLiveNode(up, v, w, 1, i + 1);
		}
		up = Bound(i + 1);
		//��������������м�֦
		if (up > bestp) {
			AddLiveNode(up, cp, cw, 0, i + 1);
		}
		if (H.IsEmputy()) {
			break;
		}
		HN = H.Delete();
		E = HN.ptr;
		cw = HN.Weight;
		up = HN.uprofit;
		cp = HN.profit;
		i = HN.Level;
		//��¼����Ĳ��������н�
		if (cp == bestp) {
			BestE = E;
			lev = i;
		}
		
	}
	i = lev;
    while (i--&& BestE)
	{
		BestX[items[i].ID] = BestE->flag;
		BestE = BestE->parent;
	}
	cout << "����ֵΪ" << bestp << endl;
	for (i = 0; i < n; i++) {
		cout << BestX[i] << " ";
	}
	return 0;
}
void AddLiveNode(int up, int cp, int cw, int flag, int lev) {
	bbNode* b = new bbNode(E, flag);
	HeapNode n(up, cp, cw, lev, b);
	H.Insert(n);
}

/*
��������
10
5
2 6
2 3
6 5
5 4
4 6
*/