#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXK 27
#define MOD 1000000009
typedef long long ll;
ll f[MAXN][MAXK];
ll g[MAXN][MAXK];
ll p[MAXN][MAXK];
ll ncr[MAXK][MAXK];
void comb(){
	int i,j;
	ncr[1][0]=ncr[1][1]=1;
	for(i=2;i<MAXK;i++){
		ncr[i][0]=1;
		for(j=1;j<=i;j++){
			ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
			if(ncr[i][j]>=MOD)
				ncr[i][j]%=MOD;
		}
	}
}
void solve1(){
	int i,j;
	for(j=1;j<MAXK;j++){
		f[1][j]=j;
		for(i=2;i<MAXN;i++){
			f[i][j]=j*f[i-1][j];
			if(f[i][j]>=MOD)
				f[i][j]%=MOD;
			if(i%2==0){
				f[i][j]=f[i][j]-f[i/2][j]+MOD;
				if(f[i][j]>=MOD)
					f[i][j]%=MOD;
			}
		}		
	}
}
void solve2(){
	solve1();
	int i,j;
	ll ans;
	for(j=1;j<MAXK;j++){
		ans=1;
		for(i=1;i<MAXN;i++){
			ans*=j;
			if(ans>=MOD)
				ans%=MOD;
			g[i][j]=ans-f[i][j]+MOD;
			if(g[i][j]>=MOD)
				g[i][j]%=MOD;
		}
	}
}
void solve3(){
	solve2();
	comb();
	int i,j,k;
	for(i=1;i<MAXN;i++){
		p[i][1]=g[i][1];
		for(j=2;j<MAXK;j++){
			p[i][j]=g[i][j];
			for(k=1;k<j;k++){
				p[i][j]-=(p[i][k]*ncr[j][k])%MOD;
				if(p[i][j]<0)
					p[i][j]+=MOD;
			}
		}
	}
	for(i=1;i<MAXN;i++){
		for(j=1;j<MAXK;j++){
			p[i][j]*=ncr[26][j];
			if(p[i][j]>=MOD)
				p[i][j]%=MOD;
		}
	}
}
int main(){
	solve3();
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		printf("%lld\n",p[n][k]);	
	}
	return 0;
}
