#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int a[MAX];
typedef long long ll;
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ll val=0,cnt=1;
	for(i=1;i<n;i++){
		if(a[i]>=a[i-1])
			cnt++;
		else{
			val+=(cnt*(cnt+1))/2;
			cnt=1;
		}
	}
	val+=(cnt*(cnt+1))/2;
	printf("%lld\n",val);
	return 0;
}
