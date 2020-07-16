#include<iostream>
#include<vector>
using namespace std;
typedef struct TreeNode* Tree;
int N;
int type;
bool flag1,flag2;
int num[1005];
vector<int> res;

void output(int p) {
	if (flag1 == flag2) {
		flag2 = num[p / 2] > num[p];
	}


	if (p * 2 > N) {
		for (auto w:res) {
			printf("%d ", w);
		}
		printf("%d\n", num[p]);
		return;
	}
	res.push_back(num[p]);
	if (2 * p + 1 <= N) {
		output(2 * p + 1);
	}
	output(2 * p);
	
	res.pop_back();
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}
	flag1 = flag2 = num[1] > num[2];
	if (flag1) {
		num[0] = 0x7fffffff;
	}
	else {
		num[0] = 0x7fffffff + 1;
	}
	output(1);
	if (flag1 == flag2) {
		if (flag1) {
			printf("Max Heap\n");
		}
		else {
			printf("Min Heap\n");
		}
	}
	else {
		printf("Not Heap\n");
	}
	return 0;
}