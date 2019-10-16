#include<iostream>
using namespace std;
#define N 6
void MatrixChain(int *p,int n,int m[][N+1],int s[][N+1]){
	//A[i][i]等数为0;
	for(int i=0;i<=n;i++){
		m[i][i]=0;
	}

	for(int r = 2;r<=n;r++){
		//r为要计算的矩阵的长度
		//从2开始计算到最大长度
		for(int i=1;i<=n-r+1;i++){

			//i为要计算的子序列的
			int j=i+r-1;

			/*
			按正常顺序算出吗m[i][k]的值
			列如{a1,a2,a3}
			m[1][3]=m[2][3]+数
			即顺序a1*(a2*a3)的计算次数

			列如{a1,a2,a3,a4}
			m[1][4]=m[2][4]+数
			即a1*(a2*a3*a4)序列的乘法次数
			*/
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];

			/*
			记录Aij可以划分成哪两个序列相乘
			例如s[1][6]=3点，代表将1-6划分成两部分
			1-3一组，4-6一组
			*/
			s[i][j]=i;

			/*
			检测从i到j的子序列是否还有更小的值
			列如{A1,A2,A3,A4}
			要求下列乘法顺序的乘法次数
			(A1*A2)*(A3*A4)
			(A1*A2*A3)*A4 
			*/
			for(int k=i+1;k<j;k++){
				/*
				关于对p[i-1]*p[k]*p[j]的理解
				矩阵的行列大小，肯定是首位的行数和末尾的列数
				k为被乘数的行数
				列如(A1*A2)*(A3*A4)
				k即为A3的行数，或A1*A2的列数，或A2的列数
				*/
				int t=m[i][k]+m[k+1][k]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

void TraceBack(int i,int j,int s[][N+1]){
	if(i==j)return;
	/*
	若能分解成更小的的序列，则先输入更小的寻别上的值
	*/
	TraceBack(i,s[i][j],s);
	TraceBack(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j]
	<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}

int main(){
	int p[N+1]={30,35,15,5,10,20,25};
	int m[N+1][N+1] = {0},s[N+1][N+1]={0};

	MatrixChain(p,N,m,s);
	cout<<"要进行的最大次数运算为："<<m[1][N]<<endl;

	TraceBack(1,6,s);
	int n;
	cin>>n;
	return 0;
}
