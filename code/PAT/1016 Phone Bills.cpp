#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int rate[24];
struct record_Input {
	int code;//八位数编码
	bool flag;//true代表上线，false代表下线
	bool operator<(const record_Input other)const {
		return code < other.code;
	}
};

struct customer {
	string name;
	vector<record_Input> in;//记录数组
	int Money = 0;

	void AddIn(record_Input record) {
		in.push_back(record);
	}
	void show() {
		cout << name << endl;
		sort(in.begin(), in.end());//拍序
		int size = in.size() - 1,time;
		int d, h, s;
		for (int i = 0; i < size; i++) {
			if (!in[i].flag || in[i + 1].flag) {
				continue;
			}
			time = in[i + 1].code - in[i].code;
			
		}
	}
};
map<string, customer> ma;
int main() {
	int i, n, j;
	float daycount = 0;
	int sum = 0, radix = 100, temp;
	for (i = 0; i < 24; i++) {
		cin >> rate[i];
		daycount += rate[i] * 6.0;
	}
	cin >> n;
	string name, time, type;
	string online = "on-line";
	string offline = "off-line";
	for (i = 0; i < n; i++) {
		cin >> name >> time >> type;		if (ma.count(name) == 0) {
			customer cc;
			cc.name = name;
			ma.insert(make_pair(name, cc));
		}
		for (j = 0; j < 10; j += 3) {
			temp = (time[j] - '0') * 10 + (time[j + 1] - '0') * 10;
			sum = sum * radix + temp;
		}
		record_Input in;
		in.code = sum;
		in.flag = online == type;
		ma[name].AddIn(in);
	}
	for (map<string, customer>::iterator ite = ma.begin(); ite != ma.end(); ite++) {

	}
	return 0;
}
/*
写题的效率有点慢，要读懂提，构思好再往下写
构思的时候写出流程草图及大概的步骤
*/