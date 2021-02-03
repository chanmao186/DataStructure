#include<iostream>
#include<vector>

using namespace std;
int main() {
	vector<vector<int>>coordinates;
	coordinates = { {2,1} ,{4,2},{6,3} };
	int x, y;
	bool res = true;
	x = coordinates[1][0] - coordinates[0][0];
	y = coordinates[1][1] - coordinates[0][1];
	if (x == 0) {
		x = coordinates[0][0];
		for (auto& p : coordinates) {
			res = p[0] == x;
			if (!res) {
				break;
			}
		}
	}
	else {
		float k, a, b;
		int c;
		k = y / x;
		c = coordinates[0][1] - k * coordinates[0][0];
		for (auto& p : coordinates) {
			a = p[0];
			b = p[1];
			res = b == a * k + c;
			if (!res)break;
		}
	}
	res;

	return 0;
}