#include<bits/stdc++.h>
using namespace std;
#define MAX 501
char a[MAX][MAX];
int d[MAX][MAX], r[MAX][MAX];
int R,C;
void read()
{
	scanf("%d %d", &R, &C);
	for(int i=0;i<R;i++)
		scanf("%s", a[i]);
	for(int i=R-1;i>=0;i--){
		for(int j=C-1;j>=0;j--){
			if('x' == a[i][j])
				r[i][j]=d[i][j]=-1;
			else {
				r[i][j]=r[i][j+1]+1;
				d[i][j]=d[i+1][j]+1;
				if(j==C-1)
					r[i][j]-=1;
				if(i==R-1)
					d[i][j]-=1;
			}
		}
	}
}
void solve()
{
	int mx = 0;
	for(int x=0; x<R; x++){
		for(int y=0; y<C; y++){
			for(int rid=r[x][y]; rid>0; rid--){
				for(int did=d[x][y]; did>0 && did+rid>mx; did--){
					if( r[x+did][y]>=rid && d[x][y+rid]>=did )
						mx = rid + did;
				}
			}
		}
	}
	if(mx == 0)
		printf("impossible\n");
	else
		printf("%d\n", mx*2);
}

int main()
{
	read();
	solve();
    return 0;
}
