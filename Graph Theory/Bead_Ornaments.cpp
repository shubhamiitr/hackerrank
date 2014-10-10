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
#define MATH
#ifdef MATH
	int modulo(int a,LL b,int p=MOD){
		LL x=1,y=a;while(b){if(b&1){x*=y;if(x>=p)x%=p;}y*=y;if(y>=p)y%=p;b/=2;}
		return x;
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
	LL lcm(LL a,LL b){
		return a*b/gcd(a,b);
	}
	int extended_euclid(int a, int b, int &x, int &y) { // Finds x,y such that d = ax + by
		int xx=y=0;
		int yy=x=1;
		int q,t;
		while (b) {
			q=a/b;
			t=b; 
			b=a%b; 
			a=t;
			t=xx; xx=x-q*xx; x=t;
			t=yy; yy=y-q*yy; y=t;
		}
		return a;
	}
	VI modular_linear_equation_solver(int a, int b, int p) { 	// All solutions to ax = b (mod p)
		int x,y;
		VI solutions;
		int d=extended_euclid(a,p,x,y);
		if (!(b%d)) {
			x*=(b/d);
			if(abs(x)>=p)
				x%=p;
			if(x<0)
				x+=p;
			for(int i=0;i<d;i++)
				solutions.push_back((x+i*(p/d))%p);
		}
		return solutions;
	}
	int invmod(int a, int p) {
		int x, y;
		int d = extended_euclid(a,p,x,y);
		if (d > 1) return -1;
		return (x%p+p)%p;
	}
	void linear_diophantine(int a, int b, int c, int &x, int &y) { 	// Computes x and y such that ax + by = c; on failure, x = y =-1
		int d = gcd(a,b);
		if(c%d){
			x=y=-1;
		}
		else{
			x = c/d * invmod(a/d, b/d);
			y = (c-a*x)/b;
		}
	}
#endif
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
	LL factorial(LL n,int p){   // Complexity: p*{log(n)/log(p)}
		LL x=1;
		while(n>1){
			x=(x*((n/p)%2?p-1:1))%p;
			for(int i=2;i<=n%p;i++)
				x=(x*i)%p;
			n/=p;
		}
		return x%p;
	}
	LL powOfMod(LL n,int p){
		LL cnt=0;
		while(n>=p){
			n/=p;
			cnt+=n;
		}
		return cnt;
	}
	LL ncr(LL n,LL r,int p){  
		LL modpow=powOfMod(n,p)-powOfMod(n-r,p)-powOfMod(r,p); // Can be greater than or equal to zero only
		if(modpow>0)
			return 0;
		LL ans=(factorial(n-r,p)*factorial(r,p))%p;
		ans=modulo(ans,p-2,p);	
		ans=(ans*factorial(n,p))%p;
		return ans;
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
#ifdef MAXFLOW
	#define MAXV 101
	int V;
	int rGraph[MAXV][MAXV];
	int graph[MAXV][MAXV];
	int parent[MAXV];
	bool visited[MAXV];
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
			for(v=1;v<=V;v++){
				if(visited[v]==false && rGraph[u][v]>0){
					q.push(v);
					parent[v]=u;
					visited[v]=true;
				}
			}
		}
		return (visited[t]==true);
	}
	int fordFulkerson(int s,int t){ 	// Complexity: O(V*E^2) | O(V*MaxFlow) 
		int u,v;
		for(u=1;u<=V;u++){
			for(v=1;v<=V;v++)
				rGraph[u][v]=graph[u][v];
		}
		int maxflow=0,pathflow;
		while(bfs(s,t)){ // bfs(s,t) or dfs(s,t)
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
		for(int i=1;i<=V;i++){
			if(rGraph[s][i] && !visited[i])
				dfs(i);
		}
	}
	vector<PII> mincut(){
		fordFulkerson(1,V);
		clr(visited);
		dfs(1);
		int i,j;
		vector<PII> cuts;
		for(i=1;i<=V;i++){
			for(j=1;j<=V;j++){
				if(visited[i] && !visited[j] && graph[i][j]){
					cuts.pb(mp(i,j));
				}
			}
		}
		return cuts;
	}
#endif
#ifdef MAXBPM
	int N,M; // N X M Bipartite Graph
	#define MAXN 1001 
	VI adj[MAXN]; 
	bool visited[MAXN];
	int lft[MAXN],rht[MAXN];
	bool dfs(int u){
		if(visited[u])
			return false;
		visited[u]=true;
		int sz=adj[u].size(),i,v;
		for(i=0;i<sz;i++){
			v=adj[u][i];
			if(rht[v]==-1){
				rht[v]=u;
				lft[u]=v;
				return true;
			}
		}
		for(i=0;i<sz;i++){
			v=adj[u][i];
			if(dfs(rht[v])){
				rht[v]=u;
				lft[u]=v;
				return true;
			}
		}
		return false;
	}
	int match(){
		int i;
		set(lft);
		set(rht);
		int ans=0;
		bool done;
		do{
			done=true;
			clr(visited);
			for(i=1;i<=N;i++){
				if(lft[i]==-1 && dfs(i)){
					done=false;
				}
			}
		}while(!done);
		for(i=1;i<=N;i++){
			ans+=(lft[i]!=-1);
			adj[i].clear();
		}
		return ans;
	}
#endif
LL b[10];
int main(){
	int t,i,n;
	LL sm,ans;
	SD(t);
	while(t--){
		SD(n);
		for(i=0;i<n;i++)
			SL(b[i]);
		if(n==1){
			if(b[0]==1)
				b[0]++;
			ans=modulo(b[0],b[0]-2);
			PLN(ans);
			continue;
		}
		ans=1;
		sm=0;
		for(i=0;i<n;i++){
			ans*=modulo(b[i],b[i]-1);
			if(ans>=MOD)
				ans%=MOD;
			sm+=b[i];
		}
		if(n>2){
			ans*=modulo(sm,n-2);
			if(ans>=MOD)
				ans%=MOD;
		}
		PLN(ans);
	}
	return 0;
}
