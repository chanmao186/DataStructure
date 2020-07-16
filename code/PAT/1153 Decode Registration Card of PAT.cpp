#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Student {
	string code;
	int score;
	Student(string c, int s) {
		code = c; score = s;
	}
};

struct siteNode {
	int score = 0;
	int num = 0;
};

bool comp_level(Student s1, Student s2) {
	if (s1.score == s2.score) {
		return s1.code < s2.code;
	}
	return s1.score > s2.score;
}
struct DateNode
{
	int sit = 0;
	int num = 0;
	DateNode(int s, int n) {
		sit = s; num = n;
	}
};

bool comp_dateNode(DateNode d1, DateNode d2) {
	if (d1.num == d2.num) {
		return d1.sit < d2.sit;
	}
	return d1.num > d2.num;
}
siteNode sites[1005];
vector<Student> level[3];
unordered_map<int, unordered_map<int,int>> dates;
unordered_map<int, vector<DateNode>> _dates;

int main() {
	int N, M,score,sit,date,_lev;
	char lev;
	string code;
	code.resize(13);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", &code[0]);
		scanf("%d", &score);

		sit = atoi(code.substr(1, 3).c_str());
		date = atoi(code.substr(4, 6).c_str());

		switch (code[0])
		{
		case 'T':
			level[0].push_back(Student(code, score));
			break;
		case 'A':
			level[1].push_back(Student(code, score));
			break;
		case 'B':
			level[2].push_back(Student(code, score));
			break;
		}

		sites[sit].score += score;
		sites[sit].num++;

		dates[date][sit]++;
	}

	for (int i = 0; i < 3;i++) {
		sort(level[i].begin(), level[i].end(), comp_level);
	}

	vector<DateNode> temp;
	for (auto d : dates) {
		temp.clear();
		for (auto n : d.second) {
			temp.push_back(DateNode(n.first, n.second));
		}
		sort(temp.begin(), temp.end(), comp_dateNode);
		_dates[d.first] = temp;
	}

	int Type;
	for (int i = 1; i <= M; i++) {
		scanf("%d", &Type);
		printf("Case %d: %d ", i,Type);
		switch (Type)
		{
		case 1:
			scanf(" %c", &lev);		
			printf("%c\n", lev);
			switch (lev)
			{
			case 'T':
				_lev = 0;
				break;
			case 'A':
				_lev = 1;
				break;
			case 'B':
				_lev = 2;
				break;
			}

			for (auto s : level[_lev]) {
				printf("%s %d\n", s.code.c_str(), s.score);
			}

			if (level[_lev].size() == 0) {
				printf("NA\n");
			}
			break;
		case 2:
			scanf("%d", &sit);
			printf("%03d\n", sit);
			if (sites[sit].num == 0) {
				printf("NA\n");
			}
			else {
				printf("%d %d\n", sites[sit].num, sites[sit].score);
			}
			break;
		case 3:
			scanf("%d", &date);
			printf("%06d\n", date);
			if (_dates.count(date) == 0) {
				printf("NA\n");
			}else
			for (auto d : _dates[date]) {
				printf("%03d %d\n", d.sit, d.num);
			}
			break;
		}
	}
	return 0;
}
