#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2000000
#define MOD 1000000007
struct cut{
	ll val;
	int hor;
};
bool compare(cut a,cut b){
	return a.val>b.val;
}
cut c[MAX];
int main(){
	int t,n,m,s,i;
	ll ans;
	int xc,yc;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		s=0;
		for(i=1;i<m;i++)
		{
			scanf("%lld",&c[s].val);
			c[s++].hor=1;
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld",&c[s].val);
			c[s++].hor=0;
		}
		sort(c,c+s,compare);
		ans=0;
		xc=yc=0;
		for(i=0;i<s;i++){
			if(c[i].hor==1){
				ans+=c[i].val*(yc+1);
				if(ans>=MOD)
					ans%=MOD;
				xc++;
			}
			else{
				ans+=c[i].val*(xc+1);
				if(ans>=MOD)
					ans%=MOD;
				yc++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
