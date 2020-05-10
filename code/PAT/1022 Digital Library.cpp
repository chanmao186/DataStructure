#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include <string>
using namespace std;
#define Max 10010
//struct Book {
//	string id;
//	string name;
//	string author;
//	string publisher;
//	int year;
//	Book(string id, string name, string author, string publisher, int year) {
//
//	}
//	Book() {}
//};

unordered_map<string, set<string>> namel;
unordered_map<string, set<string>> authorl;
unordered_map<string, set<string>> yearl;
unordered_map<string, set<string>> pulisherl;
unordered_map<string, set<string>> keyl;

void Select(unordered_map<string, set<string>>& libray, string key) {
	if (libray.count(key) == 0) {
		cout << "Not Found" << endl;
	}
	else {
		for (auto e: libray[key]) {
			cout << e << endl;
		}
	}
}

int main() {	
	string id;
	string name;
	string author;
	string tkey;
	string key;
	string publisher;
	string year;
	int n,i,j;
	cin >> n;
	getchar();
	for (i = 0; i < n; i++) {
		getline(cin,id);
		getline(cin, name);
		getline(cin, author);
		getline(cin, key);
		getline(cin, publisher);
		getline(cin, year);
		namel[name].insert(id);
		authorl[author].insert(id);
		pulisherl[publisher].insert(id);
		yearl[year].insert(id);
		tkey = "";
		for (j = 0; j < key.length(); j++) {
			if (key[j] != ' ') {
				tkey += key[j];
			}
			else {
				keyl[tkey].insert(id);
				tkey = "";
			}
		}
		if (tkey.length() > 0) {
			keyl[tkey].insert(id);
		}
	}
	int op;
	cin >> op;
	getchar();
	string opstr;
	int num;
	for (i = 0; i < op; i++) {
		getline(cin, opstr);
		cout << opstr << endl;
		num = opstr[0] - '0';
		string s(opstr, 3);
		switch (num)
		{
		case 1:
			Select(namel, s);
			break;
		case 2:
			Select(authorl, s);
			break;
		case 3:
			Select(keyl, s);
			break;
		case 4:
			Select(pulisherl, s);
			break;
		case 5:
			Select(yearl, s);
			break;
		}
	}

}
/*
不难，仔细就行
*/