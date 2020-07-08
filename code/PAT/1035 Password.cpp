#include<iostream>
#include<vector>
using namespace std;

struct User {
	string name;
	string psd;
};

bool Modify(string& psd) {
	bool flag = false;
	for (auto &c:psd) {
		switch (c)
		{
		case '1':
			c = '@';
			flag = true;
			break;
		case '0':
			c = '%';
			flag = true;
			break;
		case 'l':
			c = 'L';
			flag = true;
			break;
		case 'O':
		    c = 'o';
			flag = true;
			break;
		}
	}
	return flag;
}

int main() {
	int N;
	
	cin >> N;
	string name, psd;
	vector<User> user;
	User u;
	for (int i = 0; i < N; i++) {
		cin >> name >> psd;
		if (Modify(psd)) {
			u.name = name;
			u.psd = psd;
			user.push_back(u);
		}
	}

	if (user.size() == 0) {
		if (N == 1) {
			printf("There is 1 account and no account is modified\n");
			
		}
		else
		{
			printf("There are %d accounts and no account is modified\n",N);
		}
		
	}
	else
	{
		cout << user.size() << endl;
		for (auto x : user) {
			cout << x.name << " " << x.psd << endl;
		}
	}
	return 0;
}