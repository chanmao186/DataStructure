#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;
#define N 1000005
int n;
int a = 0;
long long carry[33] = { 0 };
struct IP {
	int len;
	int date[4] = { 0 };
	long long ID = 0;
	int app;
	IP(string& str) {
		app = a++;
		string num;
		int d = 0;
		long long temp;
		bool s = false;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '.' || str[i] == '/') {
				temp = atoi(num.c_str());
				num = "";
				date[d] = temp;
				ID += temp * carry[24 - d * 8];
				d++;
				if (str[i] == '/')s = true;
			}
			else {
				num += str[i];
			}
		}

		temp = atoi(num.c_str());

		if (s) {
			len = temp;
		}
		else {
			ID += temp * carry[24 - d * 8];
			date[d] = temp;
			d++;
			len =d * 8;
		}

	};

	bool operator < (IP& other)const {
		if (ID == other.ID) {
			if (len == other.len) {
				return app < other.app;
			}
			return len < other.len;
		}
		return ID < other.ID;
	};

	bool CanMerge(IP& other) {
		if (len > other.len) {
			return false;
		}

		return ID / carry[32 - len] == other.ID / carry[32 - len];
	};

};

int main() {
	int i,temp=1;
	vector<IP> IPBool;
	vector<IP> out;
	carry[0] = carry[1]=1;
	for (i = 2; i < 33; i++) {
		carry[i] = carry[i - 1] * 2;
	}
	cin >> n;
	getchar();
	string str;
	for (i = 0; i < n; i++) {
		getline(cin, str);
		IPBool.push_back(IP(str));
	}
	sort(IPBool.begin(), IPBool.end());
	temp = IPBool.size() - 1;
	for (i = 0; i < temp; i++) {
		if (!IPBool[i + 1].CanMerge(IPBool[i])) {
			out.push_back(IPBool[i]);
		}
	}
	out.push_back(IPBool[n - 1]);

	for (auto e : out) {
		cout << e.date[0] << "." << e.date[1] << "." << e.date[2] << "." << e.date[3] << "/" << e.len << endl;
	}
	return 0;
}
/*
60·Ö£¬ÔÝÎ´¶Á¶®Ìâ
*/