#include<iostream>
using namespace std;
bool normal[1000] = { false };
int main() {
	string s1, s2, res;
	cin >> s1 >> s2;
	int P = 'A' - 'a';
	for (auto& c : s2) {
		normal[c] = true;
		if (c >= 'a' && c <= 'z') {
			normal[c + P] = true;
		}
		if (c >= 'A' && c <= 'Z') {
			normal[c - P] = true;
		}
	}

	for (auto& c : s1) {
		//if (c == '_')continue;
		if (!normal[c]) {

			if (c >= 'a' && c <= 'z') {
				normal[c + P] = true;
			}
			if (c >= 'A' && c <= 'Z') {
				normal[c - P] = true;
			}

			normal[c] = true;
			res += c;
		}
	}	

	for (auto& c : res) {
		if (c >= 'a' && c <= 'z') {
			printf("%c", c + P);
		}
		else {
			printf("%c", c);
		}
	}

	return 0;
}