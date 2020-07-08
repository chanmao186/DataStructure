#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
	string name;
	char gender;
	string ID;
	int grade;
};

bool comp_up(Student& s1, Student& s2) {
	return s1.grade > s2.grade;
}

bool comp_low(Student& s1, Student& s2) {
	return s1.grade < s2.grade;
}

int main() {
	int N;
	Student s;
	cin >> N;
	vector<Student> male;
	vector<Student> female;
	for (int i = 0; i < N; i++) {
		cin >> s.name >> s.gender >> s.ID >> s.grade;
		if (s.gender == 'M') {
			male.push_back(s);
		}
		else {
			female.push_back(s);
		}
	}
	sort(male.begin(), male.end(), comp_low);
	sort(female.begin(), female.end(), comp_up);
	if (female.size() == 0) {
		cout << "Absent" << endl;
	}
	else {
		cout << female[0].name << " " << female[0].ID << endl;
	}

	if (male.size() == 0) {
		cout << "Absent" << endl;
	}
	else {
		cout << male[0].name << " " << male[0].ID << endl;
	}

	if (female.size() && male.size()) {
		int res = female[0].grade - male[0].grade;
		cout << res << endl;
		
	}
	else {
		cout << "NA" << endl;
	}

	return 0;
}