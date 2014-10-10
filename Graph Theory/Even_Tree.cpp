#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int cnt[MAX];
int vis[MAX];
vector<int> adj[MAX];
void dfs(int n){
	if(vis[n]==1)
		return;
	vis[n]=1;
	cnt[n]=1;
	int s=adj[n].size();
	for(int i=0;i<s;i++)
	if(vis[adj[n][i]]==0){
		dfs(adj[n][i]);
		cnt[n]+=cnt[adj[n][i]];
	}
	return;
}
int main(){
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int ans=0;
	for(i=2;i<=n;i++)
	if(cnt[i]%2==0){
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
