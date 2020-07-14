#include<iostream>
#include<stack>

#include<vector>
using namespace std;


int num[1005];
int main() {
	int M, N, K, temp;
	cin >> M >> N >> K;
	for (int z = 0; z < K; z++) {
		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}
		stack <int>s;
		temp = 1;
		for (int i = 1; i <= N; i++) {
			if (s.empty()) {
				s.push(temp++);
			}
			while (s.top() != num[i])
			{
				s.push(temp++);
				if (s.size() > M || s.top() > N) {
					cout << "NO" << endl;
					goto La;
				}
			}
			s.pop();
		}
		if (s.empty())
			cout << "YES" << endl;

	La:temp = 0;
		
	}

	return 0;
}