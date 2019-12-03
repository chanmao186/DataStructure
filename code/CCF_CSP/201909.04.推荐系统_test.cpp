#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
#define M 55
struct Item {
public:
	long long ID;//iD 为种类和商品Id的编码1000005 
	long long Score;
	Item(long long id, long long score) :ID(id), Score(score) {
	}
	bool operator< (const Item& item) const {
		return this->Score == item.Score ? this->ID < item.ID : this->Score > item.Score;
	}
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long ShowNum[M] = { 0 };
	int	Num;
	const long long mul = (long long)(1e10);
	long long a;
	int m, n, i, j, ID, Score, op, opNum, type;
	cin >> m >> n;

	set<Item> ItemsArray;
	unordered_map<long long, set<Item>::iterator> um;
	for (i = 0; i < n; i++) {
		cin >> ID >> Score;
		for (j = 0; j < m; j++) {
			a = j * mul + ID;
			um[a] = ItemsArray.insert(Item(a, Score)).first;
		}
	}

	cin >> op;
	for (i = 0; i < op; i++) {
		cin >> opNum;
		switch (opNum) {
		case 1:
			cin >> type >> ID >> Score;
			a = type * mul + ID;
			um[a] = ItemsArray.insert(Item(a, Score)).first;
			break;
		case 2:
			cin >> type >> ID;
			a = type * mul + ID;
			ItemsArray.erase(um[a]);
			break;
		case 3:
			cin >> Num;
			vector< vector<int> > Show(m);
			for (j = 0; j < m; j++) {
				cin >> ShowNum[j];
			}
			for (auto& x : ItemsArray) {
				a = x.ID / mul;
				if (Show[a].size() < ShowNum[a]) {
					Show[a].push_back(x.ID % mul);
					if (--Num == 0) {
						break;
					}
				}
			}
			for (auto& x : Show) {
				if (x.empty()) {
					cout << "-1" << endl;
				}
				else {
					for (auto e : x) {
						cout << e << " ";
					}
					cout << endl;
				}
			}
			break;
		}
	}

	return 0;
}