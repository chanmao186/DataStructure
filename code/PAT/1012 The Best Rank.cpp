#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int type;
const int Max = 0x7fffffff;
struct Node {
	//a,c,m,e
	int score[4];
	int rank[4];
};
struct student
{
	string ID;
	Node  node;
	bool operator< (const student other)const {
		return node.score[type] > other.node.score[type];
	}
};

int main() {

	vector<student> students;
	map<string, Node> mp;
	int n, m;
	cin >> n >> m;
	int i, j;

	//输入学生信息
	for (i = 0; i < n; i++) {
		student	stu;
		cin >> stu.ID >> stu.node.score[1] >> stu.node.score[2] >> stu.node.score[3];
		stu.node.score[0] = (stu.node.score[1] + stu.node.score[2] + stu.node.score[3]) / 3;
		students.push_back(stu);
	}
	int temp = 1;
	//计算学生的排名
	for (i = 0; i < 4; i++) {
		type = i;
		sort(students.begin(), students.end());
		students[0].node.rank[type] = 1;
		for (j = 1; j < n; j++) {
			//并列排名是按1 1 3 4这样的顺序计算的
			if (students[j].node.score[type] == students[j - 1].node.score[type]) {
				students[j].node.rank[type] = students[j - 1].node.rank[type];
				temp++;
			}
			else {
				students[j].node.rank[type] = students[j - 1].node.rank[type] + temp;
				temp = 1;
			}
		}
	}

	for (auto x : students) {
		mp.insert(make_pair(x.ID, x.node));
	}
	string ID;

	char name[4] = { 'A','C','M','E' };
	int flag = 0, rank;
	for (i = 0; i < m; i++) {
		cin >> ID;
		if (mp.count(ID) > 0) {
			Node node = mp[ID];
			rank = Max;
			for (j = 0; j < 4; j++) {
				if (rank > node.rank[j]) {
					flag = j;
					rank = node.rank[j];
				}
			}
			cout << rank << " " << name[flag] << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
	return 0;
}