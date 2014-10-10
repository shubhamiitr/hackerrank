#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int a[MAX];
int main(){
	int n,k,i;	
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int unfair=2000000000;
	for(i=0;i<=n-k;i++){
		unfair=min(unfair,a[i+k-1]-a[i]);
	}
	printf("%d\n",unfair);
	return 0;
}
