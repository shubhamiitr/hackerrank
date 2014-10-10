#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n,i,j,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=0;i<100;i++){
		for(j=0;j<a[i];j++)
			printf("%d ",i);
	}			
	return 0;
}
