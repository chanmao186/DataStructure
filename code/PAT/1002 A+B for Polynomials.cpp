#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int exponent;
	double cofficent;
	Node(int e, double c) {
		exponent = e;
		cofficent = c;
	}
	Node() {}

};

int main() {
	int k;
	int e;
	double c;
	cin >> k;
	vector<Node> Polynormal1, Polynormal2, sum;
	while (k--) {
		cin >> e >> c;
		Polynormal1.push_back(Node(e, c));
	}
	cin >> k;
	while (k--)
	{
		cin >> e >> c;
		Polynormal2.push_back(Node(e, c));
	}
	vector<Node>::iterator p1, p2;

	p1 = Polynormal1.begin();
	p2 = Polynormal2.begin();

	while (p1 != Polynormal1.end() && p2 != Polynormal2.end())
	{
		if (p1->exponent > p2->exponent) {
			sum.push_back(Node(p1->exponent, p1->cofficent));
			p1++;
		}
		else if (p1->exponent < p2->exponent) {
			sum.push_back(Node(p2->exponent, p2->cofficent));
			p2++;
		}
		else {
			e = p1->cofficent + p2->cofficent;
			//如果合并结果为0，则跳过
			if (e != 0) {
				sum.push_back(Node(p1->exponent, p1->cofficent + p2->cofficent));
			}

			p1++;
			p2++;
		}
	}

	for (; p1 != Polynormal1.end(); p1++) {
		sum.push_back(Node(p1->exponent, p1->cofficent));
	}

	for (; p2 != Polynormal2.end(); p2++) {
		sum.push_back(Node(p2->exponent, p2->cofficent));
	}

	cout << sum.size();

	for (auto x : sum) {
		//保留一位小数
		printf(" %d %.1f", x.exponent, x.cofficent);
	}
	return 0;
}

/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/