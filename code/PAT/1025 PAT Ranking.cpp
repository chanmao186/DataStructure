#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student
{
	string id;
	int finalRank = 1;
	int localNumber = 1;
	int localRank = 1;
	int sore = 1;
	
};


bool comp(const student& a, const student& b)
{
	if (a.sore != b.sore) {
		return a.sore > b.sore;
	}
	return a.id < b.id;
}

void RankbyLocal(vector<student> &list) {
	sort(list.begin(),list.end(), comp);
	for (int i = 1; i < list.size();i++) {
		if (list[i].sore < list[i - 1].sore) {
			list[i].localRank = i+1;
		}
		else {
			list[i].localRank = list[i - 1].localRank;
		}
	}
}

void RankbyTotal(vector<student> &list) {
	sort(list.begin(), list.end(), comp);
	for (int i = 1; i < list.size(); i++) {
		if (list[i].sore < list[i - 1].sore) {
			list[i].finalRank = i+1;
		}
		else {
			list[i].finalRank = list[i - 1].finalRank;
		}
	}
}

int main() {
	int n, k;
	vector<vector<student>> ListList;
	vector<student> total;
	cin >> n;
	for (int i = 1,j; i <= n; i++) {
		cin >> k;
		vector<student> local;
		for (j = 0; j < k; j++) {
			student s;
			cin >> s.id >> s.sore;
			s.localNumber = i;
			local.push_back(s);
		}
		RankbyLocal(local);
		ListList.push_back(local);
	}
	for (auto l : ListList) {
		for (auto s : l) {
			total.push_back(s);
		}
	}
	RankbyTotal(total);
	cout << total.size() << endl;
	for (auto s : total) {
		cout << s.id << " " << s.finalRank << " " << s.localNumber << " "<<s.localRank << endl;
	}
	return 0;
}
//马虎导致参数写错的