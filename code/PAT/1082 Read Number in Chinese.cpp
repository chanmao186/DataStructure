#include<iostream>
#include<vector>
using namespace std;
string nums[15] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string pad[10] = { "","Shi","Bai","Qian","Wan","Yi" };
                 /* 0   1     2      3     4    5     */
string Orig;
vector<string>res;
int main() {
	cin >> Orig;
	int ps, p,num;
	bool flag = false,isw = false;
	if(Orig[0]=='-'){
		printf("Fu ");
		Orig = Orig.substr(1);
	}


	for (int i = 0; i < Orig.size(); i++) {
		num = Orig[i] - '0';
		p = Orig.size() - i;
		ps = (p-1) % 4;
		if (num == 0) {
			flag = true;
		}
		else {
			if (flag) {
				flag = false;
				res.push_back("ling");//0
			}

			res.push_back(nums[num]);//本位数

			if (ps != 0) {
				res.push_back(pad[ps]);//存位
			}
			if (p >= 5 && p <= 8) {
				isw = true;
			}
		}
		
		if (p == 9) {
			res.push_back("Yi");
		}

		if (p == 5&&isw) {
			res.push_back("Wan");
		}
	}
	if (res.size() == 0) {
		printf("ling");
		return 0;
	}


	cout << res[0];
	for (int i = 1; i < res.size(); i++) {
		printf(" %s", res[i].c_str());
	}

	return 0;
}