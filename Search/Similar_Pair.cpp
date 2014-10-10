#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
typedef long long ll;
vector<int> e[MAX];
int tree[MAX];
int vis[MAX];
int src[MAX];
int des[MAX];
ll ans;
int n,t;
int read(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=idx&(-idx);
	}
	return sum;
}
void update(int idx,int val){
	while(idx<MAX){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
void dfs(int n,int p){
	if(vis[n]==1)
		return;
	if((n+t)<MAX)
		ans+=read(n+t);
	else
		ans+=read(MAX-1);
	if(n>t){
		ans-=read(n-t-1);
	}
	vis[n]=1;
	update(n,1);
	int i,sz=e[n].size();
	for(i=0;i<sz;i++){
		dfs(e[n][i],n);
	}
	update(n,-1);
}
int main(){
	int i,a,b,root;
	scanf("%d%d",&n,&t);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		src[a]+=1;
		des[b]+=1;
	}
	for(i=1;i<=n;i++){
		if(src[i]>0 && des[i]==0){
			root=i;
			break;
		}
	}
	dfs(root,0);
	printf("%lld\n",ans);
	return 0;
}
