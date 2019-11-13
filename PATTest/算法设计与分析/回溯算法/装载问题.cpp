#include<iostream>
using namespace std;
#define N 10

/**
声明整形堆栈
*/
class stack{
public:
	stack(){
		n=0;
	}
	int Pop(){
		if(Empty)
			return data[--n];
		else{
			//队列已空
			cout<<"队列已空"<<endl;
			return 0;
		}
			
	}
	void Push(int num){
		if(n==N){
		cout<<"队列已满"<<endl;
		};
		data[n++]=num;
	}
	bool Empty(){
		return n;
	}
private :
	int n;
	int data[N];
};


/**
是否满足限界条件,满足为true,不满足为fakse
cn:当前运算物品下标
n:物品总数
*/
bool bound(int cn,int n){
	return cn<n;
}

/**
是否满足约束条件，满足返回true,不满足返回false
限界条件:两船都可以装下明确要装的物品的重量
cw[0]:明确分配给船0的物品重量
cw[1]:明确分配给船1的物品重量
c[0]:船0的限重
c[1]:船1的限重
*/
bool Constraint(int cw[2],int c[2],int){
	return cw[0]<c[0]&&cw[1]<c[1];
}

/**
回溯算法
*/
bool Backtrack(int w[N],int bestX[N],int c[2],int n,int r){
	bool result = false;
	int X[N]={0},bestW = 0,cw[2]={0};
	//声明堆栈
	stack s;
	s.Push(0);
	while(s.Empty()){
		if(Constraint()&&Bound()){}
		else{}
	}
	return result;
} 


int main(){
	/*
	w：物品重量数组
	n：物品的数量
	c：两船的载重
	bestX：船1钟要存放的物品
	r：剩余集装箱重量
	*/
	int w[N]={10,50,45,30,20,25,40,15,35,10},n,c[2]={150,150},bestX[N]={0},r=0;
	cout<<"请输入物品的总量(输入0：默认方案)："<<endl;
	cin>>n;

	//判读是否用默认方案
	if(n==0){
		n=10;
		r=280;
	}else{
		//输入重量
		cout<<"请按顺序输入各物品的重量:"<<endl;
		for(int i=0;i<n;i++){
			cin>>w[i];
			r+=w[i];
		}
		//输入载重
		for(int i = 0;i<2;i++){
			cout<<"请输入船"<<i<<"的载重:"<<endl;
			cin>>c[i];
		}
	}

	//判读是否超重
	if(r<c[0]+c[1]){

	}else{
		cout<<"物品超重，二船无法装下"<<endl;
	}
	return 0; 
}
