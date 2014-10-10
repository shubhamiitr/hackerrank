#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

#define SET(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define SQ(x) (x)*(x)
#define mp make_pair  
#define fst first
#define snd second
#define pb push_back
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define PI(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define end printf("\n")
#define spa printf(" ")
#define bsch(f,l,h) while(l<h){ int mid=(l+h)/2; if(f(mid)) h=mid; else l=mid+1;}
#define MAX 251

int n,m,k;
VI edges[MAX];
bool vis[MAX];
int lft[MAX],rht[MAX];
LL d[MAX][MAX];
PLL biker[MAX];
PLL bikes[MAX];

bool dfs(int u){
	if(vis[u])
		return false;
	vis[u]=true;
	int sz=edges[u].size(),i,v;
	for(i=0;i<sz;i++){
		v=edges[u][i];
		if(rht[v]==-1){
			rht[v]=u;
			lft[u]=v;
			return true;
		}
	}
	for(i=0;i<sz;i++){
		v=edges[u][i];
		if(dfs(rht[v])){
			rht[v]=u;
			lft[u]=v;
			return true;
		}
	}
	return false;
}
bool match(LL tm){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(d[i][j]<=tm)
				edges[i].pb(j);
		}
	}
	SET(lft);
	SET(rht);
	int ans=0;
	bool done;
	do{
		done=true;
		CLR(vis);
		for(i=1;i<=n;i++){
			if(lft[i]==-1 && dfs(i)){
				done=false;
			}
		}
	}while(!done);
	for(i=1;i<=n;i++){
		ans+=(lft[i]!=-1);
		edges[i].clear();
	}
	return (ans>=k ? true:false);
}

int main(){
	SI(n);SI(m);SI(k);
	int i,j;
	for(i=1;i<=n;i++){
		SL(biker[i].fst);
		SL(biker[i].snd);
	}
	for(i=1;i<=m;i++){
		SL(bikes[i].fst);
		SL(bikes[i].snd);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			d[i][j]=SQ(biker[i].fst-bikes[j].fst)+SQ(biker[i].snd-bikes[j].snd);
		}
	}
	LL l=0,h=1E16;
	bsch(match,l,h)
	PL(l);
	end;
	return 0;
}
