#include<iostream>
#include <algorithm>
using namespace std;
long long ToDecimal(long long radix, string N) {
	long long result = 0;
	int num;
	for (int i = 0; i < N.length(); i++) {
		if (isdigit(N[i])) {
			num = N[i] - '0';
		}
		else {
			num = N[i] - 'a' + 10;
		}
		result = result * radix + num;
	}
	return result;
}
int main() {
	string N1, N2;
	int tag, num;
	long long n1, n2, right, left, mid, radix;
	left = n1 = n2 = 0;
	cin >> N1 >> N2 >> tag >> radix;

	if (tag == 2) {
		swap(N1, N2);
	}
	n1 = ToDecimal(radix, N1);
	for (int i = 0; i < N2.length(); i++) {
		if (isdigit(N2[i])) {
			num = N2[i] - '0';
		}
		else {
			num = N2[i] - 'a' + 10;
		}
		left = max(left, (long long)num);
	}
	left++;
	right = max(n1, left);//防止出现n1最大值小于n2的基数的情况

	while (left <= right) {
		mid = (left + right) / 2;
		n2 = ToDecimal(mid, N2);
		/*
		if的判断顺序挺重要的，要先判断n2是否是负数（越界）再比较大小
		*/
		if (n1 == n2) {
			cout << mid << endl;
			return 0;
		}
		else if (n2 > n1||n2<0) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			
		}
	}
	cout << "Impossible" << endl;
	return 0;
}
/*
总结：这道题好难
首先题目没给基数的范围
那么就必须在基数可能的最小值和可能的最大值里面用二分查找找了
没办法确定范围，只能用long long来当做范围来用
在计算long long的时候还要考虑越界，越界了就表示太大了


isdigits()和isalpha()挺好用的两个函数
if语句的判断次序也很重要
*/