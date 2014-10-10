#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX];
int main(){
	int s,i,j,k,val;
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<s;i++){
		for(j=0;j<i;j++){
			if(a[j]>a[i]){
				val=a[i];
				for(k=i-1;k>=j;k--){
					a[k+1]=a[k];
				}
				a[j]=val;
			}
		}
		for(j=0;j<s;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	return 0;
}
