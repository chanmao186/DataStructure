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
	right = max(n1, left);//��ֹ����n1���ֵС��n2�Ļ��������

	while (left <= right) {
		mid = (left + right) / 2;
		n2 = ToDecimal(mid, N2);
		/*
		if���ж�˳��ͦ��Ҫ�ģ�Ҫ���ж�n2�Ƿ��Ǹ�����Խ�磩�ٱȽϴ�С
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
�ܽ᣺��������
������Ŀû�������ķ�Χ
��ô�ͱ����ڻ������ܵ���Сֵ�Ϳ��ܵ����ֵ�����ö��ֲ�������
û�취ȷ����Χ��ֻ����long long��������Χ����
�ڼ���long long��ʱ��Ҫ����Խ�磬Խ���˾ͱ�ʾ̫����


isdigits()��isalpha()ͦ���õ���������
if�����жϴ���Ҳ����Ҫ
*/