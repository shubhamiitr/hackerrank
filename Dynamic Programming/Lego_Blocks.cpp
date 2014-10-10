#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1001
#define MOD 1000000007
ll g[MAX][MAX];
ll h[MAX];
ll f[MAX];
void solve(){
	int i,j;
	f[0]=1;
	for(j=1;j<MAX;j++){
		f[j]=f[j-1];
		if(j>1)
			f[j]+=f[j-2];
		if(j>2)
			f[j]+=f[j-3];
		if(j>3)
			f[j]+=f[j-4];
		if(f[j]>=MOD)
			f[j]%=MOD;
	}
	for(j=1;j<MAX;j++){
		g[1][j]=f[j];
		for(i=2;i<MAX;i++){
			g[i][j]=g[i-1][j]*f[j];
			if(g[i][j]>=MOD)
				g[i][j]%=MOD;
		}
	}
}
int main(){
	int t,n,m,i,j;
	solve();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			h[i]=g[n][i];
			for(j=1;j<i;j++){
				h[i]-=(h[j]*g[n][i-j])%MOD;
				if(h[i]<0)
					h[i]+=MOD;
			}
		}
		printf("%lld\n",h[m]);
	}
	return 0;
}
