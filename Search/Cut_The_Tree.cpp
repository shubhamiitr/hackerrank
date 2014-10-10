#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int w[MAX];
vector<int> e[MAX];
int nw[MAX];
int vis[MAX];
int dfs(int x){
	if(vis[x]==1)
		return 0;
	vis[x]=1;
	nw[x]=w[x];
	int i,s=e[x].size();
	for(i=0;i<s;i++){
		nw[x] =nw[x]+dfs(e[x][i]);
	}
	return nw[x];
}
int main(){
	int n,i,x,y,tw=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		tw+=w[i];
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	int d=INT_MAX;
	for(i=1;i<=n;i++){
		d=min(d,abs(tw-2*nw[i]));
	}
	printf("%d\n",d);
	return 0;
}
