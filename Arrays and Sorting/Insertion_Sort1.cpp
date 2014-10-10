#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX];
int main(){
	int n,i,j,val;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	val=a[n-1];
	for(i=n-2;i>=-1;i--){
		if(a[i]>val && a[i+1]!=a[i] && i>=0){
			a[i+1]=a[i];
			for(j=0;j<n;j++)
				printf("%d ",a[j]);
			printf("\n");
		}
		else{
			a[i+1]=val;
			for(j=0;j<n;j++)
				printf("%d ",a[j]);
			printf("\n");
			break;
		}
	}
	return 0;
}
