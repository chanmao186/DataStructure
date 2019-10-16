/* */
#include<iostream>
using namespace std;

#define M 16
int Board[M][M]= {0};
int tile = 1;
void ChessBoard(int tr,int tc,int dr,int dc,int size);
int main()
{
	int i,j;

	ChessBoard(0,0,1,6,16);

	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			printf("%3d",Board[i][j]);
		}
		cout<<endl;
	}


	cin>>i;
	return 0;
}

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
	if(size==1)return;
	int t =tile++,
		s=size/2;
	if (dr<tr+s&&dc<tc+s)
		ChessBoard(tr,tc,dr,dc,s);
	else{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}

	if(dr<tr+s&&dc>=tc+s)
		ChessBoard(tr,tc+s,dr,dc,s);
	else{
		Board[tr+s-1][tc+s]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}

	if(dr>=tr+s&&dc<tc+s)
		ChessBoard(tr+s,tc,dr,dc,s);
	else{
		Board[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}

	if(dr>=tr+s&&dc>=tc+s)
		ChessBoard(tr+s,tc+s,dr,dc,s);
	else{
		Board[tr+s][tc+s]=t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	}
}
