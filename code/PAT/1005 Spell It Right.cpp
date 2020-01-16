#include <iostream>
#include<stack>
using namespace std;
string shownum[10] = {
  "zero","one","two","three","four","five","six","seven","eight","nine"
};
int main() {
	string num;
	cin >> num;
	int sum=0, cnum;
	for (int i = 0; i < num.length(); i++) {
		cnum = num[i] - '0';
		sum += cnum;
	}
	stack<string> s;

	if (sum>10) {
		while (sum / 10)
		{
			s.push(shownum[sum % 10]);
			sum /= 10;
		}
		if (sum > 0) {
			s.push(shownum[sum]);
		}
		cout << s.top();
		s.pop();
		while (!s.empty())
		{
			cout << " " << s.top();
			s.pop();
		}
	}
	else {
		cout << shownum[sum];
	}
	cout << endl;
	return 0;
}