#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int c[MAX];
int main(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	sort(c,c+n);
	reverse(c,c+n);
	int cost=0;
	for(i=0;i<n;i++){
		cost+=(i/k+1)*c[i];
	}
	printf("%d\n",cost);
	return 0;
}
