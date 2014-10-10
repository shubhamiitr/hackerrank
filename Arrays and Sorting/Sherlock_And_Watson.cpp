#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int a[MAX];
int main(){
	int n,k,q,i;
	scanf("%d%d%d",&n,&k,&q);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	k%=n;
	while(q--){
		scanf("%d",&i);
		printf("%d\n",a[(i-k+n)%n]);
	}
	return 0;
}
