#include<iostream>
using namespace std;

int mradixin() {
	int num, left, right, now, radix=1,res=0;
	cin >> num;
	
	while (num / radix) {
		left = num / (radix * 10);
		right = num % radix;
		now = num / radix % 10;
		if (now == 0) {
			res += left * radix;
		}
		else if(now == 1)
		{
			res += left * radix + right+1;//ȫΪ0
		}
		else {
			res += (left + 1) * radix;
		}
		radix *= 10;
	}
	cout << res << endl;
	return 0;
}