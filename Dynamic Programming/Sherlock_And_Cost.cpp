#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int dp[MAX][2];
int a[MAX];
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		dp[0][0]=0;
		dp[0][1]=0;
		for(i=1;i<n;i++){
			dp[i][1]=max(dp[i-1][1]+abs(a[i]-a[i-1]),dp[i-1][0]+a[i]-1);
			dp[i][0]=max(dp[i-1][1]+a[i-1]-1,dp[i-1][0]);
		}
		printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
	}	
	return 0;
}
