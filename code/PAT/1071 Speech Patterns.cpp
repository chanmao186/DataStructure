#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<string, int>words;
string orig;

int main() {
	getline(cin, orig);
	string word;
	int p = 'A' - 'a';
	for (auto& c: orig) {
		if ((c <= 'z' && c >= 'a')||(c>='0'&&c<='9')) {
			word += c;
		}
		else if (c <= 'Z' && c >= 'A') {
			word += (c - p);
		}
		else {
			if (word.size() > 0) {
				words[word]++;
				word = "";
			}
		}
	}
	if (word.size() > 0) {
		words[word]++;
	}
	int maxn = 0;
	for (auto& w : words) {
		if (maxn < w.second) {
			maxn = w.second;
			word = w.first;
		}
		else if (maxn == w.second) {
			if (word > w.first) {
				word = w.first;
			}
		}
	}

	printf("%s %d", word.c_str(), maxn);
	return 0;
}