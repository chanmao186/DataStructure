#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct People {
	string ID;
	string Name;
	int Grade;
};
int Type = 1;
bool comp1(const People a, const People b) {
	return a.ID < b.ID;
}

bool comp2(const People a, const People b) {
	if (a.Name == b.Name) {
		return a.ID < b.ID;
	}
	return a.Name < b.Name;
}
bool comp3(const People a, const People b) {

	if (a.Grade == b.Grade) {
		return a.ID < b.ID;
	}
	return a.Grade < b.Grade;
}

int main() {
	int N;
	cin >> N >> Type;
	vector<People> Peoples;
	for (int i = 0; i < N; i++) {
		People p;
		cin >> p.ID >> p.Name >> p.Grade;
		Peoples.push_back(p);
	}
	switch (Type)
	{
	case 1:
		sort(Peoples.begin(), Peoples.end(), comp1);
		break;
	case 2:
		sort(Peoples.begin(), Peoples.end(), comp2);
		break;
	case 3:
		sort(Peoples.begin(), Peoples.end(), comp3);
		break;
	}
	for (auto p : Peoples) {
		cout << p.ID << " " << p.Name << " " << p.Grade << endl;
	}
	return 0;
}