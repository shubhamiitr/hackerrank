#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int a[MAX];
int cnt[MAX];
int main(){
	int t,n,i,c,k;
	double ans;
	scanf("%d",&t);
	while(t--){
		ans=0.0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[n]=1001;
		sort(a,a+n+1);
		k=a[0];
		c=1;
		for(i=1;i<=n;i++){
			if(a[i]!=k){
				ans+=((n+1.)*c)/(n+1.-i+c);
				k=a[i];
				c=0;
			}
			c++;
		}
		printf("%.02lf\n",ans);
	}
	return 0;
}
