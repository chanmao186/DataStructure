#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct MyList {
	int Start;
	int End;
	MyList(int s, int e) {
		Start = s;
		End = e;
	}
};
vector<MyList>mylist;
int diamond[100005] = { 0 };
int main() {
	int n, many;
	cin >> n >> many;
	int start, sum, cnt,temp;
	start = 1; sum = 0; cnt = 100000000;
	int i;
	for (i = 1; i <= n; i++) {
		cin >> diamond[i];
	}

	for (i = 0; i <= n; i++) {
		sum += diamond[i];
		if (sum >= many)break;
	}

	if (sum<many) {
		printf("1-%d\n", n);
		return 0;
	}
	else {
		sum -= diamond[i];
	}

	for (; i <= n; i++) {
		sum += diamond[i];
		temp = sum - many;
		if (temp == cnt) {
			mylist.push_back(MyList(start, i));
		}
		else if (temp>=0&&temp < cnt) {
			cnt = temp;
			mylist.clear();
			mylist.push_back(MyList(start, i));
		}

		while (sum > many) {
			sum -= diamond[start++];

			temp = sum - many;
			if (temp == cnt) {
				mylist.push_back(MyList(start, i));
			}
			else if (temp >= 0 && temp < cnt) {
				cnt = temp;
				mylist.clear();
				mylist.push_back(MyList(start, i));
			}
		}
	}

	if (mylist.size() == 0) {
		printf("1-%d\n", n);
		return 0;
	}

	for (auto& l : mylist) {
		printf("%d-%d\n", l.Start, l.End);
	}
	return 0;
}