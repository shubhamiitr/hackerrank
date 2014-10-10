#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int modulo(int a,int b,int p){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%p;
        }
        y = (y*y)%p; 
        b /= 2;
    }
    return x;
}
ll factorial(ll n,int p){   // Complexity: p*{log(n)/log(p)}
	ll x=1;
	while(n>1){
		x=(x*((n/p)%2?p-1:1))%p;
		for(int i=2;i<=n%p;i++)
			x=(x*i)%p;
		n/=p;
	}
	return x%p;
}
ll powOfMod(ll n,int p){
	ll cnt=0;
	while(n>=p){
		n/=p;
		cnt+=n;
	}
	return cnt;
}
ll ncr(ll n,ll r,int p){ 
	ll powmod=powOfMod(n,p)-powOfMod(n-r,p)-powOfMod(r,p); // Can be greater than or equal to zero only
	if(powmod>0)
		return 0;
	ll ans=(factorial(n-r,p)*factorial(r,p))%p;
	ans=modulo(ans,p-2,p);	
	ans=(ans*factorial(n,p))%p;
	return ans;
}
int main(){
	int t;
	ll n,k;
	int p;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%d",&n,&k,&p);
		printf("%lld\n",ncr(n+1,n-k,p));
	}
	return 0;
}
