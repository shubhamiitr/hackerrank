#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main(){
	int t;
	ll p,q,r;
	ll ans;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&p,&q,&r);
		p%=MOD;
		q%=MOD;
		r%=MOD;
		ans=p*q+q*r+r*p-1;
		if(ans>=MOD)
			ans%=MOD;
		ans*=(MOD+1)/2;
		if(ans>=MOD)
			ans%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
