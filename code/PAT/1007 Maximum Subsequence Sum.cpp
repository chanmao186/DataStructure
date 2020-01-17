#include<iostream>
using namespace std;
struct Node
{
	int max = 0;
	int first = 0;
	int last = 0;
};
int main() {
	Node s1, s2;
	int  temp, n;
	cin >> n;
	cin >> temp;
	s1.max = s2.max = temp > 0 ? temp : 0;
	s1.first = s2.first = temp;
	s1.last = s2.last = temp;
	bool flag = (temp >= 0);
	while (--n)
	{
		cin >> temp;
		if (s1.max == 0) {
			s1.first = temp;
		}
		s1.max += temp;
		if (s1.max < 0) {
			s1.max = 0;
		}
		if (s1.max > s2.max) {
			s2.first = s1.first;
			s2.last = temp;
			s2.max = s1.max;
		}
		if (!flag)
			flag = (temp >= 0);
	}
	if (s2.max == 0) {

		if (flag) {
			s2.first = s2.last = 0;
		}
		else {
			s2.last = temp;
		}
	}

	cout << s2.max << " " << s2.first << " " << s2.last;
	return 0;
}