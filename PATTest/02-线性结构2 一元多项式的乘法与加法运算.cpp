#include <iostream>
using namespace std;
typedef struct PolyNode* Polynomial;
struct 	 PolyNode
{
	int Coef;
	int Expon;
	Polynomial Next;
};
void attach(int Coef, int Expon, Polynomial* Poly) {
	if (Coef) {
		Polynomial p = (Polynomial)malloc(sizeof(PolyNode));
		p->Coef = Coef;
		p->Expon = Expon;
		p->Next = NULL;
		(*Poly)->Next = p;
		*Poly = p;
	}
	
}
Polynomial InputPoly() {
	int	n, c, e;
	cin >> n;
	Polynomial poly, temp;
	//����ͷ���
	poly = (Polynomial)malloc(sizeof(PolyNode));
	//������ʱ����������
	temp = poly;
	//��������0������ʱ���޷�����
	temp->Next = NULL;
	while (n--) {
		cin >> c >> e;
		attach(c, e, &temp);
	}
	return poly;
}
//�����������ʽ���
Polynomial Add(Polynomial p1, Polynomial p2) {
	Polynomial sum, temp;
	sum = (Polynomial)malloc(sizeof(PolyNode));
	temp = sum;
	temp->Next = NULL;
	p1 = p1->Next;
	p2 = p2->Next;
	while (p1 && p2)
	{
		if (p1->Expon > p2->Expon) {
			attach(p1->Coef, p1->Expon, &temp);
			p1 = p1->Next;
		}
		else if (p1->Expon < p2->Expon) {
			attach(p2->Coef, p2->Expon, &temp);
			p2 = p2->Next;
		}
		else {
			attach(p1->Coef + p2->Coef, p1->Expon, &temp);
			p1 = p1->Next;
			p2 = p2->Next;
		}
	}
	while (p1)
	{
		attach(p1->Coef, p1->Expon, &temp);
		p1 = p1->Next;
	}
	while (p2)
	{
		attach(p2->Coef, p2->Expon, &temp);
		p2 = p2->Next;
	}
	
	return sum;
}
//������������ʽ���
Polynomial Multipul(Polynomial p1, Polynomial p2) {
	Polynomial p,temp,current,t1,t2;
	int c, e, t;
	p = (Polynomial)malloc(sizeof(PolyNode));
	temp = p;
	t1 = p1->Next;
	t2 = p2->Next;
	p->Next = NULL;
	//���t1��t2�����ڣ�ֱ������0 0
	if (!t1 || !t2)return p;
	while (t2)
	{
		attach(t1->Coef * t2->Coef, e = t1->Expon + t2->Expon, &temp);		
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1)
	{
		t2 = p2->Next;
		temp = p;
		while (t2) {
			c = t1->Coef * t2->Coef;
			e = t1->Expon + t2->Expon;
			while (temp->Next&&temp->Next->Expon>e)
			{
				//Ѱ��ϵ�����ʵ���
				temp = temp->Next;
			}
			if (temp->Next && temp->Next->Expon == e) {
				current = temp->Next;
				//��¼ϵ����ӵ�ֵ
				current->Coef += c;
				//���ϵ����Ϊ0�������ϵ����ֵ
				if (!current->Coef) {
					//��ϵ��Ϊ0����ɾ������
					temp->Next = current->Next;
					free(current);
				}			
			}
			else {
				//����һ��С�ڸ����ָ�������߲�����
				current = (Polynomial)malloc(sizeof(PolyNode));
				current->Coef = c;
				current->Expon = e;
				current->Next = temp->Next;
				temp->Next = current;
				temp=current;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	return p;
}
void Output(Polynomial p) {
	if (p->Next) {
		p = p->Next;
		cout << p->Coef << " " << p->Expon;
		p = p->Next;
		while (p)
		{
			cout << " " << p->Coef << " " << p->Expon;
			p = p->Next;
		}
		cout << endl;
	}
	else {
		cout << "0 0" << endl;
	}
}
int main() {
	Polynomial p1, p2,m,s;
	p1 = InputPoly();
	p2 = InputPoly();
	m = Multipul(p1, p2);
	s = Add(p1, p2);
	Output(m);
	Output(s);
	return 0;
}