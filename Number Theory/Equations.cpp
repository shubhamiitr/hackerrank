#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define MOD 1000007
typedef long long ll;
bool prime[MAX];
int p[MAX];
int pcnt=0;
void seive(){
	int i,j;
	for(i=3;i<MAX;i+=2)
		prime[i]=true;
	prime[2]=true;
	for(i=3;i*i<MAX;i+=2)
	if(prime[i]){
		for(j=i*i;j<MAX;j+=2*i)
			prime[j]=0;
	}
	p[0]=2;
	pcnt=1;
	for(i=3;i<MAX;i+=2)
	if(prime[i])
		p[pcnt++]=i;
}
int main(){
	seive();
	int i,n,m;
	ll ans=1,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	if(prime[i]){
		m=n;
		cnt=0;
		while(m){
			m/=i;
			cnt+=m;
		}
		ans*=(2*cnt+1);
		if(ans>=MOD)
			ans%=MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
