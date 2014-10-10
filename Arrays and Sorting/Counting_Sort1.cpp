#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n,x;
	int a[100];
	for(i=0;i<100;i++)
		a[i]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=0;i<100;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
