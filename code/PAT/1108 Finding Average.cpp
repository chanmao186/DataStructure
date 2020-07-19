#include<iostream>
using namespace std;

int main() {
	int N, num = 0, mnum, mindex, start;
	float sum = 0, temp;
	bool flag, isZero;
	string in;
	cin >> N;
	for (int i = 0, j; i < N; i++) {
		cin >> in;
		flag = true;
		mnum = 0;
		start = 0;
		if (in[0] == '-') {
			start++;
		}
		for (j = start; j < in.length(); j++) {
			if (in[j] == '.') {
				mindex = j;
				mnum++;
				if (mnum > 1) {
					flag = false;
					break;
				}
				continue;
			}
			if (in[j]<'0' || in[j]>'9') {
				flag = false;
				break;
			}
		}

		if (flag) {
			if ((mnum > 0) && (mindex == start || in.length() - mindex > 3)) {
				isZero = true;
				if ((mnum > 0) && (mindex != start)  && in.length() - mindex > 3) {
					
					for (int k = mindex + 3; k < in.length(); k++) {
						if (in[k] == '0')continue;
						isZero = false;
						break;
					}
				}
				if (isZero) {
					goto out;
				}
				printf("ERROR: %s is not a legal number\n", in.c_str());
			}
			else {
			out:
				temp = atof(in.c_str());
				if (temp > 1000 || temp < -1000) {
					printf("ERROR: %s is not a legal number\n", in.c_str());
				}
				else {
					num++;
					sum += atof(in.c_str());
				}
			}
		}
		else {
			printf("ERROR: %s is not a legal number\n", in.c_str());
		}
	}

	if (num > 1) {
		printf("The average of %d numbers is %.02f", num, sum / num);
	}
	else if (num == 1) {
		printf("The average of 1 number is %.02f", sum);
	}
	else {
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
}