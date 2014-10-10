#include<bits/stdc++.h>
using namespace std;
int dp[52][52][1001];
char a[51][51];
int main(){
	int n,m,p,i,j,k,x,y;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
		for(j=0;j<m;j++)
		if(a[i][j]=='*'){
			x=i;x++;
			y=j;y++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			dp[i][j][0]= (i==1 && j==1)?0:10001;
		}
	}
	for(k=1;k<=p;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				dp[i][j][k]=10001;
				if(j>1){
					if(a[i-1][j-2]=='R')
						dp[i][j][k]=min(dp[i][j-1][k-1],dp[i][j][k]);
					else
						dp[i][j][k]=min(dp[i][j-1][k-1]+1,dp[i][j][k]);
				}
				if(j<m){
					if(a[i-1][j]=='L')
						dp[i][j][k]=min(dp[i][j+1][k-1],dp[i][j][k]);
					else
						dp[i][j][k]=min(dp[i][j+1][k-1]+1,dp[i][j][k]);
				}
				if(i<n){
					if(a[i][j-1]=='U')
						dp[i][j][k]=min(dp[i+1][j][k-1],dp[i][j][k]);
					else
						dp[i][j][k]=min(dp[i+1][j][k-1]+1,dp[i][j][k]);
				}
				if(i>1){
					if(a[i-2][j-1]=='D')
						dp[i][j][k]=min(dp[i-1][j][k-1],dp[i][j][k]);
					else
						dp[i][j][k]=min(dp[i-1][j][k-1]+1,dp[i][j][k]);
				}
				//printf("%d ",dp[i][j][k]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	int ans=INT_MAX;
	for(k=0;k<=p;k++){
		ans=min(ans,dp[x][y][k]);
	}
	if(ans<10001)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
