#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define N 10005
#define OpN 8
int n;
int dn = 0;//最后完成的进程数量 
struct Process {
	int State = 0;//0为空闲，1为发送，2为接收,3代表执行完毕 
	int cdes; //目标地址 
	int ID;//进程ID 
	void Sent(int d) {
		fun(d, 2, 1);
	}
	//因为要引用全局变量，所以实现方法写在了后面 
	void fun(int d, int ds, int ss);

	void Receive(int d) {
		fun(d, 1, 2);
	}
	char opA[OpN];
	int des[OpN];
	int pn = 0;//当前运算的位数 
	int length = 0;//可操作的指令长度 
	void Input(char op, int d) {
		opA[length] = op;
		des[length] = d;
		length++;
	}
	void Reset() {
		State = pn = length = 0;
	}
	void RunNext() {
		//空闲状态才可执行指令 
		if (State > 0) {
			return;
		}
		//执行完成，更新程序的状态为完成 
		if (pn == length) {
			State = 3;
			dn++;
			return;
		}
		if (opA[pn] == 'R') {
			Receive(des[pn++]);
		}
		else {
			Sent(des[pn++]);
		}
	}
}P[N];

queue<int> operaq;
int main() {
	int t, i, j, k, s, d;
	char op;
	cin >> t >> n;
	string str, num;
	for (i = 0; i < n; i++) {
		P[i].ID = i;
	}
	getchar();
	for (i = 0; i < t; i++) {
		dn = 0;
		for (j = 0; j < n; j++) {
			P[j].Reset();

			getline(cin, str);

			for (k = 0; k <= str.length(); k++) {
				op = str[k];
				num = "";
				for (k++; k <= str.length(); k++) {
					if (str[k] >= '0' && str[k] <= '9')
						num += str[k];
					else
						break;
				}
				P[j].Input(op, atoi(num.c_str()));
			}
			P[j].RunNext();
		}
		while (!operaq.empty())
		{
			P[operaq.front()].RunNext();
			operaq.pop();
		}
		if (dn == n) {
			cout << "0" << endl;
		}
		else {
			cout << "1" << endl;
		}
	}
	return 0;
}

void Process::fun(int d, int ds, int ss) {
	if (d == ID) {
		return;
	};//防止自己向自己发数据 
	d = d;
	if (P[d].State == ds && P[d].cdes == ID) {
		P[d].State = 0;
		operaq.push(d);
		operaq.push(ID);
	}
	else {
		State = ss;
		cdes = d;
	}
}
/*
80分代码，最后没达到满分
*/
/*
3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0
*/