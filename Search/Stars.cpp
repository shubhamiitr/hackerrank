#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100
struct point{
	ll x,y;
	int v;
};
int cross_product(point p1,point p2,point p3){
	return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}
point p[MAX];
int n;
void solve(){
	int l,r,mxm=0;
	int i,j,k,sign;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		if(i!=j){
			l=0;
			r=0;
			for(k=0;k<n;k++){
				sign=cross_product(p[i],p[j],p[k]);
				if(sign<0)
					l+=p[k].v;
				else if(sign>0)
					r+=p[k].v;
			}
			if(l<r)
				l+=max(p[i].v,p[j].v);
			else
				r+=max(p[i].v,p[j].v);
			if(l<r)
				l+=min(p[i].v,p[j].v);
			else
				r+=min(p[i].v,p[j].v);
			if(l<r){
				if(mxm<l)
					mxm=l;
			}
			else{
				if(mxm<r)
					mxm=r;
			}
		}
	}
	printf("%d\n",mxm);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld%lld%d",&p[i].x,&p[i].y,&p[i].v);
	}
	solve();
	return 0;
}
