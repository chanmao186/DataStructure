#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string>cards;
vector<string>res(55);
vector<int>order(55);

void ADDCard(string al) {
	string temp;
	for (int i = 1; i < 14; i++) {
		temp = al + to_string(i);
		cards.push_back(temp);
	}
}

int main() {
	cards.push_back("0");
	ADDCard("S");
	ADDCard("H");
	ADDCard("C");
	ADDCard("D");
	cards.push_back("J1");
	cards.push_back("J2");
	int n;
	cin >> n;
	for (int i = 1; i < 55; i++) {
		cin >> order[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 55; j++) {
			res[order[j]] = cards[j];
		}
		cards = res;
	}
	for (int i = 1; i < 54; i++) {
		cout << res[i] << " ";
	}
	cout<<res[54]<<endl;
	return 0;
}