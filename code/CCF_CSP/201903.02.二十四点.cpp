#include<iostream>
#include<stack>
using namespace std;

int main() {
	int num[4];
	char op[3];
	int n, result = 24, c, temp;
	char cop;
	cin >> n;
	stack<int> ns;
	stack<char> cs;
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
		c = num[3];
		while (!ns.empty()) {
			temp = ns.top();
			cop = cs.top();
			if (cop == '+') {
				c += temp;
			}
			else {
				c = temp - c;
			}
			ns.pop();
			cs.pop();
		}
		if (c == result) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}