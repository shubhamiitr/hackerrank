#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
int a[MAX];
int main(){
	int n,x,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]--;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=1;i<=MAX;i++)
	if(a[i]){
		printf("%d ",i);
	}
	return 0;
}
