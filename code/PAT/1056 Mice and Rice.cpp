#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1005
struct Mouse {
	int rank = -1;
	int Weight;
};
int Order[N] = { 0 };
Mouse mouses[N];
vector<int> next1,cur;
int main() {
	int rank = 0, n,group;
	cin >> n >> group;
	
	for (int i = 0; i < n; i++) {
		cin >> mouses[i].Weight;
	}

	for (int i = 0; i < n; i++) {
		cin >> Order[i];
		next1.push_back(Order[i]);
	}

	int maxw, maxm;

	while (next1.size()!=1)
	{
		cur = next1;
		next1.clear();
		for (int i = 0,j; i < cur.size();) {
			maxw = -1;
			for (j = 0; j < group&& i < cur.size();i++,j++) {
				//mouses[cur[i]].rank = rank;
				if (mouses[cur[i]].Weight > maxw) {
					maxw = mouses[cur[i]].Weight;
					maxm = cur[i];
				}
			}
			next1.push_back(maxm);
		}
		rank = next1.size() + 1;
		for (auto index : cur) {
			mouses[index].rank = rank;
		}
	}
	mouses[next1[0]].rank = 1;
	rank++;
	printf("%d", mouses[0].rank);
	for (int i = 1; i < n; i++) {
		printf(" %d", mouses[i].rank);
	}
	return 0;
}