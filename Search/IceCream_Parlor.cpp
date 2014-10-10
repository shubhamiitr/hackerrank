#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int a[MAX];
int v[MAX];
int main(){
	int t,m,n,i,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		for(i=0;i<MAX;i++){
			v[i]=0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(v[a[i]]==1)
				k=i;
			if(m>=a[i])
				v[m-a[i]]=1;
		}
		for(i=0;i<n;i++){
			if(a[i]+a[k]==m){
				printf("%d %d\n",i+1,k+1);
				break;
			}
		}
	}
	return 0;
}
