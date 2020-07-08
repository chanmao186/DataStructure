#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool up(int& i, int& j) {
	return i > j;
}

int main() {

	int N, temp, res = 0;
	vector<int> coupon, product;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		coupon.push_back(temp);
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		product.push_back(temp);
	}

	sort(coupon.begin(), coupon.end(), up);
	sort(product.begin(), product.end(), up);

	int i, j;
	i = j = 0;
	while (i<coupon.size()&&i<product.size())
	{		
		temp = coupon[i] * product[i];
		if (temp <= 0)break;
		res += temp;
		i++;
	}

	if (i == coupon.size() || i == product.size()) {
		cout << res << endl;
		return 0;
	}
	i = coupon.size()-1;
	j = product.size()-1;

	while (i >= 0&&j>=0)
	{
		temp = coupon[i] * product[j];
		if (temp <= 0)break;
		res += temp;
		i--; j--;
	}
	cout << res << endl;
	return 0;
}