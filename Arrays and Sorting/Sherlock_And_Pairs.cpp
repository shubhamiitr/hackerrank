#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int a[MAX];
typedef long long ll;
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		ll ans=0,cnt=1;
		for(i=1;i<n;i++){
			if(a[i]==a[i-1]){
				cnt++;
			}
			else{
				ans+=cnt*(cnt-1);
				cnt=1;
			}
		}
		ans+=cnt*(cnt-1);
		printf("%lld\n",ans);
	}
	return 0;
}
