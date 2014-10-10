#include<bits/stdc++.h>
using namespace std;
#define HEADER
#ifdef HEADER
	typedef long long LL;
	typedef vector<int> VI;
	typedef vector<LL> VLL;
	typedef set<int> SI;
	typedef set<LL> SLL;
	typedef pair<int,int> PII;
	typedef pair<LL,LL> PLL;
	#define set(x) memset(x,-1,sizeof x)
	#define clr(x) memset(x,0,sizeof x)
	#define sq(x) (x)*(x)
	#define mp make_pair  
	#define fst first
	#define snd second
	#define pb push_back
	#define ub upper_bound //Iterator pointing to just greater than value
	#define lb lower_bound //Iterator pointing to before just greater than value
	#define SD(x) scanf("%d",&x)
	#define SL(x) scanf("%lld",&x)
	#define SF(x) scanf("%lf",&x)
	#define SCA(x) scanf("%s",x)
	#define PD(x) printf("%d ",x)
	#define PL(x) printf("%lld ",x)
	#define PF(x) printf("%lf ",x)
	#define PCA(x) printf("%s ",x)
	#define PDN(x) printf("%d\n",x)
	#define PLN(x) printf("%lld\n",x)
	#define PFN(x) printf("%lf\n",x)
	#define PCAN(x) printf("%s\n",x)
	#define PR(x) printf(x)
	#define BSCH(f,l,h) while(l<h){ int mid=(l+h)/2; if(f(mid)) h=mid; else l=mid+1;}
#endif
#define MOD 1000000007
#define MAX 1000000
int powmod(int a,LL b){
	LL x=1,y=a;while(b){if(b&1){x*=y;if(x>=MOD)x%=MOD;}y*=y;if(y>=MOD)y%=MOD;b/=2;}
	return x;
}
int invmod(int a){
	return powmod(a,MOD-2);
}
int gcd(int a,int b){
	int temp;
	while(b){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
LL gcd(LL a,LL b){
	LL temp;
	while(b){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
#ifdef FACT 
	LL fact[MAX+1];
	LL invfact[MAX+1];
	void preproc(){
		fact[0]=1;
		int i;
		for(i=1;i<=MAX;i++){
			fact[i]=fact[i-1]*i;
			if(fact[i]>=MOD)
				fact[i]%=MOD;
		}
		invfact[0]=1;
		for(i=1;i<=MAX;i++){
			invfact[i]=invfact[i-1]*invmod(i);
			if(invfact[i]>=MOD)
				invfact[i]%=MOD;
		}
	}
#endif  
#ifdef PRIME
	bool isP[MAX+1];
	void seive(){
		int i,j;
		isP[2]=true;
		for(i=3;i<PMAX;i+=2)
			isP[i]=true;
		for(i=3;SQ(i)<PMAX;i+=2){
			for(j=SQ(i);j<PMAX;j+=2*i)
				isP[j]=false;
		}
	}
#endif
#ifdef BIT
	LL bit[MAX];
	int ar[MAX];
	void update(int i,int val){
		while(i<MAX){
			bit[i]+=val;
			i+=(i&-i);
		}
	}
	LL sum(int i){
		LL ans=0;
		while(i>0){
			ans+=bit[i];
			i-=(i&-i);
		}
		return ans;
	}
	void scale(int c){
		for(int i=1;i<MAX;i++)
			bit[i]/=c;
	}
#endif
#ifdef STREE
	LL tree[2*MAX];
	LL lazy[2*MAX];
	int ar[MAX];
	void build(int node,int start,int end){
		if(start>end)
			return;
		if(start==end){
			tree[node]=ar[start];
			return;
		}
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
	} 
	void update(int node,int start,int end,int i,int j,int value){
		if(lazy[node]!=0){
			tree[node]+=(end-start+1)*lazy[node];
			if(start!=end){
				lazy[2*node]+=lazy[node];
				lazy[2*node+1]+=lazy[node];
			}
			lazy[node]=0;
		}
		if(start>end || j<start || i>end)
			return;
		if(i<=start && end<=j){
			tree[node]+=(end-start+1)*value;
			if(start!=end){
				lazy[2*node]+=value;
				lazy[2*node+1]+=value;
			}
		}
		int mid=(start+end)/2;
		update(2*node,start,mid,i,j,value);
		update(2*node+1,mid+1,end,i,j,value);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
	LL query(int node,int start,int end,int i,int j){
		if(start>end || j<start || i>end)
			return 0;
		if(lazy[node]!=0){
			tree[node]+=(end-start+1)*lazy[node];
			if(start!=end){
				lazy[2*node]+=lazy[node];
				lazy[2*node+1]+=lazy[node];
			}
			lazy[node]=0;
		}
		if(i<=start && end<=j){
			return tree[node];
		}
		int mid=(start+end)/2;
		return query(2*node,start,mid,i,j)+query(2*node+1,mid+1,end,i,j);
	}
#endif
#define MAXFLOW
#ifdef MAXFLOW
	#define MAXV 102
	int V;
	int rGraph[MAXV][MAXV];
	int graph[MAXV][MAXV];
	int parent[MAXV];
	bool visited[MAXV];
	bool bfs(int s,int t){
		clr(visited);
		queue<int> q;
		q.push(s);
		visited[s]=true;
		parent[s]=-1;
		int u,v;
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(v=0;v<V;v++){
				if(visited[v]==false && rGraph[u][v]>0){
					q.push(v);
					parent[v]=u;
					visited[v]=true;
				}
			}
		}
		return (visited[t]==true);
	}
	bool dfs(int s,int t){
		clr(visited);
		stack<int> st;
		st.push(s);
		visited[s]=true;
		parent[s]=-1;
		int u,v;
		while(!st.empty()){
			u=st.top();
			for(v=0;v<V;v++){
				if(rGraph[u][v] && !visited[v]){
					st.push(v);
					visited[v]=true;
					parent[v]=u;
					break;
				}
			}	
			if(u==st.top()){
				st.pop();
			}
		}
		return (visited[t]==true);
	}
	int fordFulkerson(int s,int t){ 	// Complexity: O(V*E^2) | O(V*MaxFlow) 
		int u,v;
		for(u=0;u<V;u++){
			for(v=0;v<V;v++)
				rGraph[u][v]=graph[u][v];
		}
		int maxflow=0,pathflow;
		while(dfs(s,t)){
			pathflow=INT_MAX;
			for(v=t;v!=s;v=parent[v]){
				u=parent[v];
				pathflow=min(pathflow,rGraph[u][v]);
			}
			for(v=t;v!=s;v=parent[v]){
				u=parent[v];
				rGraph[u][v]-=pathflow;
				rGraph[v][u]+=pathflow;
			}
			maxflow+=pathflow;
		}
		return maxflow;
	}
	void dfs(int s){
		visited[s]=true;
		for(int i=0;i<V;i++){
			if(rGraph[s][i] && !visited[i])
				dfs(i);
		}
	}
	vector<PII> mincut(){
		fordFulkerson(0,V-1);
		clr(visited);
		dfs(0);
		int i,j;
		vector<PII> cuts;
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				if(visited[i] && !visited[j] && graph[i][j]){
					cuts.pb(mp(i,j));
				}
			}
		}
		return cuts;
	}
#endif
#define A(x) (2*(x))
#define B(x) (2*(x)+1)
int main(){
	int c;
	SD(c);
	int n,t,m,u,v,i;
	while(c--){
		SD(n);
		V=2*n+2;
		SD(t);
		SD(m);
		for(i=0;i<V;i++)
			clr(graph[i]);
		for(i=0;i<m;i++){
			SD(u);SD(v);
			graph[A(u)][B(v)]=1;
			graph[A(v)][B(u)]=1;
		}
		for(i=1;i<=n;i++){
			graph[0][A(i)]=t;
			graph[B(i)][1]=1;
		}
		PDN(fordFulkerson(0,1));
	}
	return 0;
}
