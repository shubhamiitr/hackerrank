#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
int a[MAX];
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int dif=INT_MAX;
	for(i=1;i<n;i++){
		if((a[i]-a[i-1])<dif)
			dif=a[i]-a[i-1];
	}
	for(i=1;i<n;i++)
	if(a[i]==a[i-1]+dif){
		printf("%d %d ",a[i-1],a[i]);
	}
	printf("\n");
	return 0;
}
