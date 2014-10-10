#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,i;
	ll n,x;
	int a[10];
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		for(i=0;i<10;i++)
			a[i]=0;
		x=n;
		while(x){
			a[int(x%10)]++;
			x/=10;
		}
		int cnt=0;
		for(i=1;i<10;i++)
		if(a[i]){
			if(n%i==0){
				cnt+=a[i];
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
