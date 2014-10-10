#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000002
ll ar[MAX];
int main(){
	int n,m,i,a,b,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&k);
		ar[a]+=k;
		ar[b+1]-=k;
	}
	ll maxval=0;
	for(i=1;i<=n;i++){
		ar[i]+=ar[i-1];
		if(ar[i]>maxval)
			maxval=ar[i];
	}
	printf("%lld\n",maxval);
	return 0;
}
