#include<iostream>
#include<queue>
using namespace std;

int main() {
	string Orig;
	int res=0;
	int P=0, T=0;
	cin >> Orig;
	
	for (auto& c : Orig) {
		if (c == 'T')T++;
	}

	for (auto& c : Orig) {
		switch (c)
		{
		case 'P':
			P++;
			break;
		case 'A':
			res += (P * T) % 1000000007;
			if (res >= 1000000007) {
				res %= 1000000007;
			}
			break;
		case 'T':
			T--;
			break;
		}
	}

	printf("%ld", res);
	return 0;
}
