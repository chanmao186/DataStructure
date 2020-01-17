#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

struct Person
{
	string ID;
	int start;
	int end;
};
int getTime(string time) {
	int num=0,_num;
	stringstream ss;
	ss.clear();
	time[2] = time[5] = ' ';
	ss << time;
	ss >> _num;
	num += _num * 10000;
	ss >> _num;
	num += _num * 100;
	ss >> _num;
	num += _num ;
	return num;
}
int main() {
	vector<Person> Parray;
	string ID, start,end;	
	int m;
	cin >> m;
	while (m--)
	{
		cin >> ID >> start >> end;
		Person p;
		p.ID = ID;
		p.start = getTime(start);
		p.end = getTime(end);
		Parray.push_back(p);
	}
	int s=250001, e=-1;
	for (auto x : Parray) {
		if (s > x.start) {
			s = x.start;
			start = x.ID;
		}
		if (e < x.end) {
			e = x.end;
			end = x.ID;
		}
	}
	cout << start << " " << end <<endl;
	return 0;
}
/* 要自己仔细一些了，本次因为写错一个变量名检查了两个小时*/