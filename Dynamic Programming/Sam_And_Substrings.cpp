#include<bits/stdc++.h>
using namespace std;
#define MAX 200001
#define MOD 1000000007
typedef long long ll;
char s[MAX];
ll dp[MAX][2];
int main(){
	int i,n;
	scanf("%s",s);
	n=strlen(s);
	for(i=1;i<=n;i++){
		dp[i][1]=dp[i-1][1]*10+(s[i-1]-'0')*i;
		if(dp[i][1]>=MOD)
			dp[i][1]%=MOD;
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		if(dp[i][0]>=MOD)
			dp[i][1]%=MOD;
	}
	printf("%lld\n",(dp[n][0]+dp[n][1])%MOD);
	return 0;
}
