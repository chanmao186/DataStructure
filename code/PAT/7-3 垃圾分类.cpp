#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
int n;

bool Check(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '#')return false;
	}
	return true;
}
int main() {
	cin >> n;
	int i;
	char name[10];
	int type;
	unordered_map<string, int>m;
	for (i = 0; i < n; i++) {
		scanf("%s%d", &name, &type);
		m[name] = type;
	}
	char op[10];
	int temp;
	cin >> op;
	vector<int> r;
	while (op[0] != '#')
	{
		temp = m[op];	
		r.push_back(temp);		
		scanf("%s", op);
	}

	for (auto e : r) {
		switch (e)
		{
		case 1:
			cout << "Gan laji" << endl;
			break;
		case 2:
			cout << "Shi laji" << endl;
			break;
		case 3:
			cout << "Ke Hui Shou" << endl;
			break;
		case 4:
			cout << "You Hai laji" << endl;
			break;
		default:
			cout << "?" << endl;
			break;
		}
	}
	return 0;
}