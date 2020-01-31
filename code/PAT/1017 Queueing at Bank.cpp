#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int Start = 3600 * 8;
const int End = 3600 * 17;
struct Customer
{
	Customer(int arrival, int occupied) {
		Arrival = arrival;
		Occupied = occupied;
	}
	int done;
	int Arrival = 0;
	int Occupied = 0;
	void getDone(int ctime) {
		done = ctime + Occupied;
	}
	bool operator<(Customer other)const {
		return done == other.done ? Arrival < other.Arrival : done < other.done;
	}
};
bool cmp(const Customer c1, const Customer c2) {
	return c1.Arrival < c2.Arrival;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<Customer> window;
	int Occ;  //ռ��ʱ��
	int h, m, s, temp;
	vector<Customer> cus;
	int WaitTime = 0;//	�ȴ�ʱ��
	for (int i = 0; i < n; i++) {
		scanf_s("%d:%d:%d %d", &h, &m, &s, &Occ);
		temp = h * 3600 + m * 60 + s;
		if (temp > End) {
			continue;
		}
		if (Occ > 60) {
			Occ = 60;
		}
		Customer cc(temp, Occ * 60);
		cus.push_back(cc);
	}

	sort(cus.begin(), cus.end(), cmp);
	n = cus.size();
	int cTime = Start;
	while (cus.size() > 0)
	{
		while (window.size() > 0 && window.front().done <= cTime) {
			window.erase(window.begin());
		}
		while (cus.size() > 0 && cus.front().Arrival <= cTime && window.size() < k) {
			cus.front().getDone(cTime);
			WaitTime += cTime - cus.front().Arrival;//�ۼӵȴ�ʱ��			
			window.push_back(cus.front());
			cus.erase(cus.begin());
		}
		if (window.size() > 0)
			sort(window.begin(), window.end());
		//���µ�ǰʱ��Ϊ����һ���ͻ���ɵ�ʱ��
		if (window.size() == k) {
			cTime = window.begin()->done;
		}
		else {
			cTime = cus.front().Arrival;
		}
	}
	double ave;
	if (n > 0)
		ave = WaitTime / 60.0 / n;
	else
		ave = 0;
	printf("%.1f", ave);
	return 0;
}

/*
�ܽ᣺
��������Ϊ��Ƶ��㷨���߼������⣬���²���һֱû��ͨ��
��ѵ
1.Ҫ�������������ɣ�
2.�����㷨
*/