#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	stringstream ss;
	ss.clear();
	int sum = a + b;

	//�����Ƿ��и���
	if (sum < 0) {
		cout << "-";
	}
	sum = abs(sum);
	string result, temp;

	//��������ת��
	ss << sum;
	ss >> result;

	reverse(result.begin(), result.end());
	unsigned int i = 1;
	temp += result[0];
	for (; i < result.length(); i++) {
		if (i % 3 == 0) {
			temp += ',';
		}
		temp += result[i];
	}

	reverse(temp.begin(), temp.end());

	cout << temp;
	return 0;
}