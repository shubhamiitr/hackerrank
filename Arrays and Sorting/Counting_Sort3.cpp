#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[100];
	int x,n,i;
	char s[100];
	scanf("%d",&n);
	for(i=0;i<100;i++)
		a[i]=0;
	for(i=0;i<n;i++){
		scanf("%d%s",&x,s);
		a[x]++;
	}
	printf("%d ",a[0]);
	for(i=1;i<100;i++){
		a[i]+=a[i-1];
		printf("%d ",a[i]);
	}
	return 0;
}
