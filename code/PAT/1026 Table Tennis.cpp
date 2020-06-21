#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
#define K 105
int N = 0;
int StartTime = 8 * 60 * 60;
int EndTime = 21 * 60 * 60;
int currentTime = StartTime;
bool isHaveTable = true;
int vipNumber;
int MAX = 0xfffffff;



void OutputTime(int time) {
	int h, m, s;

	h = time / 3600;
	m = time % 3600 / 60;
	s = time % 60;

	printf("%02d:%02d:%02d", h, m, s);
}
struct player {
	int Arrival;
	int Wait;
	int SeveredTime;
	int Vip = 0;
	int playTime;
	void Severed() {

		Wait = round((currentTime - Arrival) / 60.0);
		SeveredTime = currentTime;
	}
};
vector<int> vipTable;
vector<player> players;
vector<player> Result;
struct Table {
	int player = 0;
	int EndTime = StartTime;
	bool vip = false;
};
vector<Table> Tables;
bool comp(const player & a, const player & b) {
	return a.Arrival < b.Arrival;
}

bool compofSeverd(const player & a, const player & b) {
	return a.SeveredTime < b.SeveredTime;
}


int main() {
	int n;
	cin >> n;

	int h, m, s;
	for (int i = 0; i < n; i++) {
		player p;
		scanf_s("%d:%d:%d %d %d", &h, &m, &s, &p.playTime, &p.Vip);

		p.Arrival = h * 3600 + m * 60 + s;
		if (p.Arrival > EndTime) { continue; }
		//规定最大时间
		if (p.playTime > 120)p.playTime = 120;
		players.push_back(p);
	}
	//从小到大排序
	sort(players.begin(), players.end(), comp);
	int k;
	cin >> k >> m;
	for (int i = 0; i <= k; i++) {
		Table t;
		Tables.push_back(t);

	}
	int vipnum;
	for (int i = 0; i < m; i++) {
		cin >> vipnum;
		vipTable.push_back(vipnum);
		Tables[vipnum].vip = true;
	}

	if (!players.empty()) {
		vector<player>::iterator temp;
		bool flag = false;
		int NextTime = StartTime;
		if (NextTime < players[0].Arrival) {
			NextTime = players[0].Arrival;
		}
		while (NextTime < EndTime) {
			flag = false;
			currentTime = NextTime;
			NextTime = MAX;

			for (int i = 1; i <= k; i++) {
				if (Tables[i].EndTime <= currentTime&&players[0].Arrival<=currentTime) {
					if (Tables[i].vip) {
						for (temp = players.begin(); temp != players.end(); temp++) {
							if (currentTime <= temp->Arrival||temp->Vip ==1) {
								break;
							}
						}
						//查看是否找到vip
						if (temp == players.end() || temp->Vip != 1) {
							temp = players.begin();
						}
					}
					else {
						temp = players.begin();
					}

					Tables[i].player++;
					Tables[i].EndTime = currentTime + temp->playTime * 60;
					temp->Severed();
					
					Result.push_back(*temp);
					players.erase(temp);
					if (players.empty()) {
						break;
					}
				}
				if (NextTime > Tables[i].EndTime) {
					NextTime = Tables[i].EndTime;
				}
			}

			if (!players.empty()) {
				if (NextTime < players[0].Arrival)
					NextTime = players[0].Arrival;
			}
			else {
				break;
			}
		}



		///////
		sort(Result.begin(), Result.end(), compofSeverd);

		for (auto p : Result) {
			OutputTime(p.Arrival);
			cout << " ";
			OutputTime(p.SeveredTime);
			cout << " " << p.Wait << endl;
		}
	}

	cout << Tables[1].player;
	for (int i = 2; i <= k; i++) {
		cout << " " << Tables[i].player;
	}


	cout << endl;
	return 0;
}

/*
1
22:22:22 10 0
3 2
1 2

1
1:22:22 10 0
3 2
1 2

1
1:22:22 10 1
3 2
2 3
*/