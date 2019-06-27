#include<iostream>
using namespace std;
#define K 100000
//int main() {
//	int a[K];
//	int n;
//	cin >> n;
//	int First, _First, Last, sum, current;
//	First = _First = 0;
//	Last = n - 1;
//	//-1是为了去都是0的一段
//	//例如 -1 -5 0 0 0 0
//	//输出 0 0 0
//	sum = -1; current = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		current += a[i];
//		if (current < 0) {
//			current = 0;
//			_First = i + 1;
//		}
//		//必须是else if
//		//else if 可以保证都是负数的情况下输入头尾
//		else if (current > sum) {
//			First = _First;
//			sum = current;
//			Last = i;
//		}
//	}
//	if (sum < 0)sum = 0;
//	cout << sum << " " << a[First] << " " << a[Last];
//	return 0;
//}