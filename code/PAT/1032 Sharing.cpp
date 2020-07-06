#include<iostream>
using namespace std;
#define N 100005

bool flag[N] = { false };
struct Node
{
	int Next = 0;
	int flag = 0;
};
Node nodes[N];
int main() {
	int add, next, n;
	char data;
	int s1, s2;
	cin >> s1 >> s2 >> n;
	//flag[add] = flag[next] = true;
	bool type = false;
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> add>>data;
		cin >> nodes[add].Next;
	}
	int index = s1;
	while (index != -1)
	{
		nodes[index].flag = 1;
		index = nodes[index].Next;
	}
	index = s2;
	while (index != -1)
	{
		if (nodes[index].flag == 1) {
			type = true;
			result = index;
			break;
		}
		index = nodes[index].Next;
	}

	if (type) {
		printf("%05d\n", result);
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}

/*
总结1，没有注意到脏节点

2.没有考虑到第一个节点
*/