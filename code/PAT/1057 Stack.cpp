#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int>sta, num;
//set<int> num;
int main() {
	char op1[10];
	string op;
	int n, key, temp,left,right,mid;
	scanf("%d", &n);
	vector<int>res;
	for (int i = 0; i < n; i++) {
		scanf("%s", op1);
		op = op1;
		if (op == "Push") {
			scanf("%d", &key);
			sta.push_back(key);

			if (num.size() == 0) {
				mid = 0;
			}
			else {
				//¶þ·Ö²éÕÒ
				for (left = 0, right = num.size(); left < right;) {
					mid = (left + right) / 2;

					if (num[mid] < key) {
						left = mid + 1;
						mid++;
					}
					else if (num[mid] > key) {
						right = mid - 1;
						if (mid == 0 || num[mid - 1] <= key)break;
						mid--;
					}
					else {
						break;
					}
				}
			}									
			num.insert(num.begin() + mid, key);
		}
		else if (op == "Pop") {
			if (sta.size() == 0) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", sta.back());
				num.erase(find(num.begin(), num.end(), sta.back()));
				sta.pop_back();
			}
		}
		else {
			if (sta.size() == 0) {
				printf("Invalid\n");
			}
			else {

				if (num.size() % 2) {
					temp = num.size() / 2;
				}
				else {
					temp = num.size() / 2 - 1;
				}
				printf("%d\n", num[temp]);
			}
		}
	}
	return 0;
}
/*
Push 5
Push 4
Push 3
Push 2
Push 1
*/