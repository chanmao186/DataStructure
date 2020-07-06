#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXP 1000000
struct Station
{
	float Price;
	float Distance;
};

bool comp(const Station s1, const Station s2) {
	return s1.Distance < s2.Distance;
}

vector<Station> Stations;

int main() {
	int C, D, AD, N;
	cin >> C >> D >> AD >> N;
	float price;
	int  distance;
	for (int i = 0; i < N; i++) {
		cin >> price >> distance;
		Station temp;
		temp.Price = price;
		temp.Distance = distance;
		Stations.push_back(temp);
	}
	sort(Stations.begin(), Stations.end(), comp);
	//float per = 


	float cd = 0;
	int  maxdis = C * AD, rundis;
	float spend = 0, cc = 0, minp;
	//Station cs = Stations[0];
	bool flag = false;
	int sdis;
	vector<Station>::iterator cs, ts, next;
	for (cs = Stations.begin(); cs < Stations.end();) {
		//rundis = cc * AD;
		ts = cs+1;
		minp = MAXP;
		for (; ts < Stations.end() && (ts->Distance - cd) <= maxdis;ts++) {
			if (minp >= ts->Price) {
				minp = ts->Price;
				next = ts;
			}
		}


		if (minp == MAXP) {
			if ((cd + maxdis) >= D) { 
				sdis = D - cd;
				if (cc * AD >= sdis) {
					break;
				}
				else {
					spend += (sdis - cc * AD) / AD * cs->Price;
					break;
				}
				
			}
			printf("The maximum travel distance = %0.2f\n", (cd + maxdis));
			return 0;
		}
		else if (minp <= cs->Price) {
			if (next->Distance < D) {
				sdis = (next->Distance - cd) - cc * AD;
				if (sdis >= 0) {
					float zc = sdis / AD;
					spend += zc * cs->Price;
					cc = 0;
				}
				else {
					cc -= (next->Distance - cd) / AD;
				}
			}
			else {
				spend += (D - cd) / AD * cs->Price;
				break;
			}
			
		}
		else {
			if ((cd + maxdis) >= D) {
				spend += (D - cd) / AD * cs->Price;
				break;
			}
			spend += (C - cc) * cs->Price;
			cc = C - (next->Distance - cd) / 12;
		}
		cd = next->Distance;
		cs = next;
	}
	printf("%0.2f", spend);*7
	return 0;
}