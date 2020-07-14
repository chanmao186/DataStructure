#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Date {
	int add, key, next;

};
bool comp(Date& d1, Date& d2) {
	return d1.key < d2.key;
}

Date mem[100005];
vector<Date> res;
int main() {
	int N, head, add, key, next, i;
	cin >> N >> head;
	for (i = 0; i < N; i++) {
		cin >> add >> key >> next;
		mem[add].add = add;
		mem[add].key = key;
		mem[add].next = next;
	}

	next = head;
	for (next = head; next != -1; next = mem[next].next)
	{
		res.push_back(mem[next]);
	}
	if (res.empty()) {
		cout << 0 << " " << -1 << endl;
		return 0;
	}

	sort(res.begin(), res.end(), comp);
	printf("%d %05d\n", res.size(), res[0].add);

	for (i = 0; i < res.size() - 1; i++) {
		printf("%05d %d %05d\n", res[i].add, res[i].key, res[i + 1].add);
	}
	printf("%05d %d %d\n", res[i].add, res[i].key, -1);

	return 0;
}