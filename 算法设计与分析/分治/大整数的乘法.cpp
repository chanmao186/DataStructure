/*
题目描述：
给一个数n,求从1~n之间0~9每个数出现的次数
*/
#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[10] = {0};
	int temp;
	for(int i=1;i<=n;i++){
		temp=i;	
		while(temp){
			a[temp%10]++;
			temp/=10;
		}
	}

	for(int i=0;i<10;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
