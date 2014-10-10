#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5001
#define MOD 1000000009
ll fact[2*MAX];
ll invfact[2*MAX];
ll cat[MAX];
ll ans[MAX];
int pow(int a,int b){
	ll x=1,y=a;
	while(b){
		if(b&1){
			x=x*y;
			if(x>=MOD)
				x%=MOD;
		}
		y*=y;
		if(y>=MOD)
			y%=MOD;
		b/=2;
	}
	return x;
}
void factorial(){
	fact[0]=1;
	int i;
	for(i=1;i<2*MAX;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=MOD)
			fact[i]%=MOD;
	}
	invfact[0]=1;
	for(i=1;i<2*MAX;i++){
		invfact[i]=invfact[i-1]*pow(i,MOD-2);
		if(invfact[i]>=MOD)
			invfact[i]%=MOD;
	}
}
void catalan(){
	factorial();
	cat[0]=1;
	int i;
	for(i=1;i<MAX;i++){
		cat[i]=fact[2*i]*invfact[i+1];
		if(cat[i]>=MOD)
			cat[i]%=MOD;
		cat[i]=cat[i]*invfact[i];
		if(cat[i]>=MOD)
			cat[i]%=MOD;
	}
}
void solve(){
	int i,j;
	catalan();
	ll x;
	for(i=1;i<MAX;i++){
		ans[i]=0;
		for(j=1;j<=i;j++){
			x=fact[i]*invfact[j];
			if(x>=MOD)
				x%=MOD;
			x*=invfact[i-j];
			if(x>=MOD)
				x%=MOD;
			x*=cat[j];
			if(x>=MOD)
				x%=MOD;
			ans[i]+=x;
			if(ans[i]>=MOD)
				ans[i]%=MOD;
		}
	}
}
int main(){
	int t,n;
	solve();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}
