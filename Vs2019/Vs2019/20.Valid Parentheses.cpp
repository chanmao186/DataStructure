#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		for (auto& c : s) {
			if (c == '(' || c == '{' || c == '[') {
				sta.push(c);
			}
			else {
				if (sta.empty()) {
					return false;
				}
				else {
					
					switch (sta.top()) {
					case ')':
						if (c != 'c')
							return false;
						break;

					case ']':
						if (c != '[')
							return false;
						break;

					case '}':
						if (c != '{')
							return false;
						break;
					}
				}
				sta.pop();
			}
		}
		return sta.empty();
	}
};
int main() {
	string s = "(]";

	Solution f;
	f.isValid(s);
	return 0;
}