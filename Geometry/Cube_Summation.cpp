#include<bits/stdc++.h>
using namespace std;
#define MAX 101
typedef long long ll;
ll tree[MAX][MAX][MAX];
ll a[MAX][MAX][MAX];
int n;
void update(int a,int b,int c,ll val){
	int x=a,y,z;
	while(x<=n){
		y=b;
		while(y<=n){
			z=c;
			while(z<=n){
				tree[x][y][z]+=val;
				z+=(z&-z);
			}
			y+=(y&-y);
		}
		x+=(x&-x);
	}
}
ll sum(int a,int b,int c){
	int x=a,y,z;
	ll ans=0;
	while(x>0){
		y=b;
		while(y>0){
			z=c;
			while(z>0){
				ans+=tree[x][y][z];
				z-=(z&-z);
			}
			y-=(y&-y);
		}
		x-=(x&-x);
	}
	return ans;
}
ll solve(int x1,int y1,int z1,int x2,int y2,int z2){
	x1--;
	y1--;
	z1--;
	return (sum(x2,y2,z2)-sum(x1,y2,z2)-sum(x2,y1,z2)+sum(x1,y1,z2))-(sum(x2,y2,z1)-sum(x1,y2,z1)-sum(x1,y1,z2)+sum(x1,y1,z1));
}
int main(){
	int t,m,i,j,k;
	int x1,y1,z1,x2,y2,z2;
	ll w;
	scanf("%d",&t);
	char query[10];
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				for(k=0;k<=n;k++){
					tree[i][j][k]=0;
					a[i][j][k]=0;
				}
			}
		}
					
		while(m--){
			scanf("%s",query);
			if(query[0]=='U'){
				scanf("%d%d%d%lld",&x1,&y1,&z1,&w);
				update(x1,y1,z1,w-a[x1][y1][z1]);
				a[x1][y1][z1]=w;
			}
			else{
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				printf("%lld\n",solve(x1,y1,z1,x2,y2,z2));
			}
		}
	}
}
