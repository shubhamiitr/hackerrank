#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX];
int gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d ",a[0]);
		for(i=1;i<n;i++){
			printf("%d ",a[i]*a[i-1]/gcd(a[i],a[i-1]));
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}
