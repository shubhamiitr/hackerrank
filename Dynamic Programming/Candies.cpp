#include<bits/stdc++.h>
using namespace std;
#define MAX 100002
typedef long long ll;
int a[MAX];
int candies[MAX];
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	a[0]=INT_MAX;
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1])
			candies[i]=candies[i-1]+1;
		else
			candies[i]=1;
	}
	for(i=n-1;i>=1;i--){
		if(a[i]>a[i+1])
			candies[i]=max(candies[i+1]+1,candies[i]);
	}
	int sum=0;
	for(i=1;i<=n;i++){
		sum+=candies[i];
	}
	printf("%d\n",sum);
	return 0;
}
