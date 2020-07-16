#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct People {
	string name;
	int age;
	int worlth;
	People(string n, int a, int w) {
		name = n;
		age = a;
		worlth = w;
	}
};

bool comp(People& p1, People& p2) {
	if (p1.worlth == p2.worlth) {
		if (p1.age == p2.age) {
			return p1.name < p2.name;
		}
		else {
			return p1.age < p2.age;
		}
	}
	return p1.worlth > p2.worlth;
}
vector<People> peoples,res;
int book[205] = { 0 };

int main() {
	int N, K;
	cin >> N >> K;
	char name[10];
	int age, worlth;
	for (int i = 0; i < N; i++) {
		cin >> name >> age >> worlth;
		peoples.push_back(People(name, age, worlth));
	}
	sort(peoples.begin(), peoples.end(), comp);
	for (auto& p : peoples) {
		if (++book[p.age] <= 100) {
			res.push_back(p);
		}
	}

	//sort(res.begin(), res.end(), comp);
	int n, a1, a2; bool flag;
	for (int i = 1; i <= K; i++) {
		cin >> n >> a1 >> a2;
		flag = false;
		printf("Case #%d:\n", i);//注意输出的标点符号
		for (auto& p : res) {
			if (p.age >= a1 && p.age <= a2) {
				flag = true;
				printf("%s %d %d\n", p.name.c_str(), p.age, p.worlth);
				n--;
				if (n == 0) {					
					break;
				}
			}			
		}
		if (!flag) {
			printf("None\n");
		}
	}
	return 0;
}
/*
特别注意输出的标点符号
还有输出的数量，可以减少算法的运行的时间

*/