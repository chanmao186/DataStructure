#include<iostream>
#include<queue>
using namespace std;

int main() {
	int num[4];
	char op[3];
	int n, result = 24, c, temp;
	char cop;
	cin >> n;
	queue<int> ns;
	queue<char> cs;
	for (int i = 0, j; i < n; i++) {
		c = 0;
		for (j = 0; j < 3; j++) {
			cin >> num[j] >> op[j];
		}
		cin >> num[3];

		for (j = 0; j < 3; j++) {
			if (op[j] == 'x') {
				num[j + 1] *= num[j];
			}
			else if (op[j] == '/') {
				num[j + 1] = num[j] / num[j + 1];
			}
			else {
				ns.push(num[j]);
				cs.push(op[j]);
			}
		}
		ns.push(num[3]);
		c = ns.front();
		ns.pop();
		while (!cs.empty()) {
			temp = ns.front();
			cop = cs.front();
			if (cop == '+') {
				c += temp;
			}
			else {
				c-=temp;
			}
			ns.pop();
			cs.pop();
		}
		//cout<<c<<endl;
		if (c == result) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
