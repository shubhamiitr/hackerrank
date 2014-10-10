#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000
ll a[MAX];
int main(){
	int n,i;
	ll c=0,s=0,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		c+=a[i]*(i+1);
		s+=a[i];
	}
	ans=c;
	for(i=1;i<n;i++){
		c-=s;
		c+=a[i-1]*n;
		if(c>ans)
			ans=c;
	}
	printf("%lld\n",ans);
	return 0;
}
