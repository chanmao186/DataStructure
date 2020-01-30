#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int rate[24];
double daycount = 0;
double hourRate[24];

struct record_Input {
	bool flag;//true代表上线，false代表下线
	int data[3];
	int Month;
	record_Input(string s) {
		sscanf_s(s.data(), "%d:%d:%d:%d", &Month, &data[0], &data[1], &data[2]);
	}
	int Value() {
		return data[0] * 10000 + data[1] * 100 + data[2];
	}
	double Money() {
		double temp = 0.0;
		temp = data[0] * daycount + data[2] * rate[data[1]] * 0.01;
		for (int i = 0; i < data[1]; i++) {
			temp += hourRate[i];
		}
		return temp;
	}
	int Time() {
		int temp = data[0] * 24 * 60 + data[2];
		for (int i = 0; i < data[1]; i++) {
			temp += 60;
		}
		return temp;
	}
	bool operator<(record_Input other) {
		return this->Value() < other.Value();
	}
};

struct record_Out
{
	int start[3], end[3];
	int spend = 0;
	double Money = 0;
	record_Out(record_Input s, record_Input e) {
		for (int i = 0; i < 3; i++) {
			start[i] = s.data[i];
			end[i] = e.data[i];
		}

		Money = e.Money() - s.Money();
		spend = e.Time() - s.Time();
	}

	void show() {
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", start[0], start[1], start[2], end[0], end[1], end[2], spend, Money);
	}
};
struct customer {
	string name;
	vector<record_Input> in;//记录数组
	vector<record_Out> out;
	double Money = 0;
	int Month = 0;
	void AddIn(record_Input record) {
		in.push_back(record);
	}
	void show() {
		sort(in.begin(), in.end());//拍序
		int size = in.size() - 1, time;
		for (int i = 0; i < size; i++) {
			if (in[i].flag==true && in[i + 1].flag==false) {
				record_Out o(in[i], in[i + 1]);
				out.push_back(o);
				Money += o.Money;
				i++;
			}		
		}
		if (in.size() > 0) {
			Month = in[0].Month;
		}
		if (Money > 0.0) {
			cout << name;
			printf(" %02d\n", Month);
			for (auto x : out) {
				x.show();
			}
			printf("Total amount: $%.2f\n", Money);
		}
	}
};
map<string, customer, less<string>> ma;
int main() {
	int i, n, j;

	int sum = 0, radix = 100, temp;
	for (i = 0; i < 24; i++) {
		cin >> rate[i];
		hourRate[i] = rate[i] * 0.6;
		daycount += hourRate[i];
	}
	cin >> n;
	string name, time, type;
	string online = "on-line";
	for (i = 0; i < n; i++) {
		cin >> name >> time >> type;
		if (ma.count(name) == 0) {
			customer cc;
			cc.name = name;
			ma.insert(make_pair(name, cc));
		}
		record_Input in(time);
		in.flag = online == type;
		ma[name].AddIn(in);
	}

	for (auto x:ma) {
		x.second.show();
	}
	return 0;
}
/*
写题的效率有点慢，要读懂提，构思好再往下写
构思的时候写出流程草图及大概的步骤

第二次总结
1.工程的思维还是不够，应该想出具体的解题思路在下手，不能一边写一边想
2.多次用到i+1换成一个变量，防止弄混
*/
/*
写题的效率有点慢，要读懂提，构思好再往下写
构思的时候写出流程草图及大概的步骤

第二次总结
1.工程的思维还是不够，应该想出具体的解题思路在下手，不能一边写一边想
2.多次用到i+1换成一个变量，防止弄混


第三次总结
三天了，终于全对了！！
*/