#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int p[MAX];
int main(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	sort(p,p+n);
	int ans=0;
	for(i=0;i<n;i++){
		if(k>=p[i]){
			ans++;
			k-=p[i];
		}
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}
