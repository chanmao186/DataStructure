/* 
进行全排列的问题
*/
#include<iostream>
using namespace std;

#define MAX 1000
void Swap(char &a,char&b){
	char c=a;
	a=b;
	b=c;
}

/*
a 数组
b 打印的起始位置
cb 进行运算的元素位置
e 打印的终点位置
*/
void Perm(char a[],int b,int cb,int e){
	//运行到最后一个元素时，进行打印
	if(cb==e){
		cout<<a[b];
		for(int i=b+1;i<e;i++){
			cout<<' '<<a[i];
		}
		cout<<endl;
		return;
	}
	for(int i=cb;i<e;i++){
		Swap(a[cb],a[i]);
		Perm(a,b,cb+1,e);
		Swap(a[cb],a[i]);
	}
}
int main(){
	int n,b,e;
	char a[MAX];
	cout<<"请输入要输入的元素个数："<<endl;
	cin>>n;
	cout<<"请输入元素："<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"请输入要打印的起始位置："<<endl;
	cin>>b;
	cout<<"请输入要打印的终点位置："<<endl;
	cin>>e;
	if(b>e||e>n){
		cout<<"输入错误"<<endl;
	}else{
		Perm(a,b-1,b-1,e);
	}
	return 0;
}

/*
测试：
4
A B C D
1
4
*/
