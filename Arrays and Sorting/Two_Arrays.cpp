#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX],b[MAX];
int main(){
	int t,n,k,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		reverse(b,b+n);
		for(i=0;i<n;i++){
			if((a[i]+b[i])<k)
				break;
		}
		if(i<n)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
