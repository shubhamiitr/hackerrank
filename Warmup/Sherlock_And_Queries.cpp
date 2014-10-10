#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
#define MOD 1000000007
ll a[MAX];
int b[MAX];
int c[MAX];
ll val[MAX];
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=0;i<m;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=n;i++)
		val[i]=-1;
	for(i=0;i<m;i++){
		if(val[b[i]]==-1)
			val[b[i]]=c[i];
		else{
			val[b[i]]*=c[i];
			if(val[b[i]]>=MOD)
				val[b[i]]%=MOD;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n/i;j++)
		if(val[j]!=-1){
			a[i*j]*=val[j];
			if(a[i*j]>=MOD)
				a[i*j]%=MOD;
		}
	}
	for(i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	return 0;
}
