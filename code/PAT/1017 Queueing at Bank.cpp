#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define MaxK 100
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
		return done < other.done;
	}
};
bool cmp(const Customer c1, const Customer c2) {
	return c1.Arrival < c2.Arrival;
}
int main() {
	int n, k;
	cin >> n >> k;
	set<Customer> window;
	int MaxOccupide = 60;
	string arr;
	int Occ;  //占用时间
	int h, m, s, temp;
	vector<Customer> cus;
	vector<Customer> wait;
	int WaitTime = 0;//	等待时间
	for (int i = 0; i < n; i++) {
		cin >> arr >> Occ;
		sscanf_s(arr.data(), "%d:%d:%d", &h, &m, &s);

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

	sort(cus.begin(), cus.end(),cmp);

	for (vector<Customer>::iterator x = cus.begin(); x != cus.end(); x = cus.begin()) {
		if (x->Arrival >= Start)break;
		WaitTime += Start - x->Arrival - 1;
		wait.push_back(*x);
		cus.erase(cus.begin());
	}

	int cTime = Start;
	int _internal = 1;
	while (wait.size() > 0 || cus.size() > 0)
	{
		WaitTime += wait.size() * _internal;
		if (cus.size() > 0 && cus.front().Arrival == cTime) {
			wait.push_back(cus.front());
			cus.erase(cus.begin());
		}

		if (window.size() > 0 && window.begin()->done == cTime) {
			window.erase(window.begin());
		}

		while (window.size() < k && wait.size() > 0)
		{
			wait.front().getDone(cTime);
			window.insert(wait.front());
			wait.erase(wait.begin());
		}

		if (window.size() == 0) {
			_internal = cus.front().Arrival - cTime;
			cTime = cus.front().Arrival;
		}
		else if(cus.size()==0){
			_internal = window.begin()->done - cTime;
			cTime = window.begin()->done - cTime;
		}
		else {
			_internal = max(window.begin()->done, cus.front().Arrival) - cTime;
			cTime = max(window.begin()->done, cus.front().Arrival);
		}
	}
	double ave = WaitTime / 60.0;
	printf("%.1f", ave);
	return 0;
}