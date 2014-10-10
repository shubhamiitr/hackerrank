#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 41
#define MAX 500000
int a[MAXN];
bool prime[MAX];
int cnt[MAX];
int ans[MAXN];
void seive(){
	int i,j;
	for(i=3;i<MAX;i+=2){
		prime[i]=true;
	}
	prime[2]=true;
	for(i=3;i*i<MAX;i+=2)
	if(prime[i]){
		for(j=i*i;j<MAX;j+=2*i)
			prime[j]=false;
	}
	cnt[1]=0;
	for(i=2;i<MAX;i++)
	{
		cnt[i]=cnt[i-1];
		if(prime[i])
			cnt[i]++;
	}
}
void process(){
	seive();
	int i;
	a[0]=1;
	for(i=1;i<MAXN;i++){
		a[i]=a[i-1];
		if(i>=4)
			a[i]+=a[i-4];
	}
	for(i=1;i<MAXN;i++){
		ans[i]=cnt[a[i]];
	}
}
int main(){
	process();
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
