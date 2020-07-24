#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define in true
#define out false
int N, K;
struct Node
{
	string id;
	int time;
	bool state;//in true,false out
};

struct QNode {
	int time, num;
};
bool cmp(Node& n1, Node& n2) {
	return n1.time < n2.time;
}
unordered_map<string, int>cord;
unordered_map<string, int>parlTime;
bool valid[10005] = { false };
vector<QNode>qu;
vector<Node>Orgi, res;
vector<string> mcar;
int maxt = 0;

int main() {
	int h, d, s, i,id,mt;
	string st;
	cin >> N >> K;
	Orgi.resize(N + 1);
	qu.resize(K);
	for (i = 1; i <= N; i++) {
		cin >> Orgi[i].id;
		scanf("%d:%d:%d", &h, &d, &s);
		Orgi[i].time = h * 3600 + d * 60 + s;
		cin >> st;
		if (st == "in") {
			Orgi[i].state = in;
		}
		else {
			Orgi[i].state = out;
		}
	}

	for (i = 0; i < K; i++) {
		scanf("%d:%d:%d", &h, &d, &s);
		qu[i].time = h * 3600 + d * 60 + s;
		qu[i].num = 0;
	}

	sort(Orgi.begin() + 1, Orgi.end(), cmp);

	for (i = 1; i < Orgi.size(); i++) {
		if (Orgi[i].state == in) {
			cord[Orgi[i].id] = i;
		}
		else {
			if (cord[Orgi[i].id] != 0) {
				id = cord[Orgi[i].id];
				cord[Orgi[i].id] = 0;
				mt = Orgi[i].time - Orgi[id].time;
				parlTime[Orgi[i].id] += mt;
				//寻找停泊最长时间的
				if (maxt == parlTime[Orgi[i].id]) {
					mcar.push_back(Orgi[i].id);
				}
				else if (maxt < parlTime[Orgi[i].id]) {
					mcar.clear();
					mcar.push_back(Orgi[i].id);
					maxt = parlTime[Orgi[i].id];
				}

				valid[i] = valid[id] = true;
			}
		}
	}

	for (i = 0; i < Orgi.size(); i++) {
		if (valid[i]) {
			res.push_back(Orgi[i]);
		}
	}

	int curn = 0;
	i = 0;
	for (auto& car : res) {
		for (; i < qu.size()&&car.time>qu[i].time; i++) {
			qu[i].num = curn;
		}
		if (car.state == in) {
			curn++;
		}
		else {
			curn--;
		}
	}
	for (auto& q : qu) {
		printf("%d\n", q.num);
	}
	sort(mcar.begin(), mcar.end());

	for (auto& c : mcar) {
		printf("%s ", c.c_str());
	}
	printf("%02d:%02d:%02d", maxt / 3600, maxt % 3600 / 60, maxt % 60);
	return 0;
}