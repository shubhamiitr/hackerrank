#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
int a[MAX];
typedef long long ll;
int main(){
	int t,n,i,larg;
	ll val;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		larg=0;
		val=0;
		for(i=n-1;i>=0;i--){
			if(a[i]>=larg){
				larg=a[i];
			}
			else{
				val+=larg-a[i];
			}
		}
		printf("%lld\n",val);
	}
}
