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
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n) FOR(i,0,n-1)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define BSCH(f,l,h) while(l<h){ int mid=(l+h)/2; if(f(mid)) h=mid; else l=mid+1;}
#define MAX 100001
#define MOD 1000003
int ar[MAX];
int p[MAX];
int d[MAX];
LL prod[MAX];
LL fact[MOD];
void preprocess(){
	fact[0]=1;
	for(int i=1;i<MOD;i++){
		fact[i]=fact[i-1]*i;
		if(fact[i]>=MOD)
			fact[i]%=MOD;
	}
}
int powmod(int a,LL b){
	LL x=1,y=a;while(b){if(b&1){x*=y;if(x>=MOD)x%=MOD;}y*=y;if(y>=MOD)y%=MOD;b/=2;}
	return x;
}
int invmod(int a){
	return powmod(a,MOD-2);
}
LL factorial(LL n){   
	if(n<MOD)
		return fact[n];
	return 0;
}
LL tree1[2*MAX];
LL lazy1[2*MAX];

void build1(int node,int start,int end){
	if(start>end)	
		return;
	if(start==end){
		tree1[node]=powmod(d[start],p[start]);
		return;
	}
	int mid=(start+end)/2;
	build1(2*node,start,mid);
	build1(2*node+1,mid+1,end);
	tree1[node]=tree1[2*node]*tree1[2*node+1];
	if(tree1[node]>=MOD)
		tree1[node]%=MOD;
}
void update1(int node,int start,int end,int i,int j,LL value){
	if(lazy1[node]!=0){ //This node needs to be updated
		tree1[node]*=powmod((prod[end]*invmod(prod[start-1]))%MOD,lazy1[node]);
		if(tree1[node]>=MOD)
			tree1[node]%=MOD;
		if(start!=end){
			lazy1[2*node]+=lazy1[node];
			lazy1[2*node+1]+=lazy1[node];
		}
		lazy1[node]=0;
	}
	if(start>end || j<start || i>end)
		return;
	if(i<=start && end<=j){
		tree1[node]*=powmod((prod[end]*invmod(prod[start-1]))%MOD,value);
		if(tree1[node]>=MOD)
			tree1[node]%=MOD;
		if(start!=end){
			lazy1[2*node]+=value;
			lazy1[2*node+1]+=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update1(2*node,start,mid,i,j,value);
	update1(2*node+1,mid+1,end,i,j,value);
	tree1[node]=tree1[2*node]*tree1[2*node+1];
	if(tree1[node]>=MOD)
		tree1[node]%=MOD;
}
int query1(int node,int start,int end,int i,int j){
	if(start>end || j<start || i>end)
		return 1;
	if(lazy1[node]!=0){ //This node needs to be updated
		tree1[node]*=powmod((prod[end]*invmod(prod[start-1]))%MOD,lazy1[node]);
		if(tree1[node]>=MOD)
			tree1[node]%=MOD;
		if(start!=end){
			lazy1[2*node]+=lazy1[node];
			lazy1[2*node+1]+=lazy1[node];
		}
		lazy1[node]=0;
	}
	if(i<=start && end<=j)
		return tree1[node];
	int mid=(start+end)/2;
	LL val1=query1(2*node,start,mid,i,j);
	LL val2=query1(2*node+1,mid+1,end,i,j);
	val1*=val2;
	if(val1>=MOD)
		val1%=MOD;
	return val1;
}
LL tree2[2*MAX];
LL lazy2[2*MAX];
void build2(int node,int start,int end){
	if(start>end)
		return;
	if(start==end){
		tree2[node]=p[start];
		return;
	}
	int mid=(start+end)/2;
	build2(2*node,start,mid);
	build2(2*node+1,mid+1,end);
	tree2[node]=tree2[2*node]+tree2[2*node+1];
}
void update2(int node,int start,int end,int i,int j,int value){
	if(lazy2[node]!=0){
		tree2[node]+=(end-start+1)*lazy2[node];
		if(start!=end){
			lazy2[2*node]+=lazy2[node];
			lazy2[2*node+1]+=lazy2[node];
		}
		lazy2[node]=0;
	}
	if(start>end || end<i || start>j)
		return;
	if(i<=start && end<=j){
		tree2[node]+=(end-start+1)*value;
		if(start!=end){
			lazy2[2*node]+=value;
			lazy2[2*node+1]+=value;
		}
		return;
	}
	int mid=(start+end)/2;
	update2(2*node,start,mid,i,j,value);
	update2(2*node+1,mid+1,end,i,j,value);
	tree2[node]=tree2[2*node]+tree2[2*node+1];
}
LL query2(int node,int start,int end,int i,int j){
	if(start>end || end<i || start>j)
		return 0;
	if(lazy2[node]!=0){
		tree2[node]+=lazy2[node];
		if(start!=end){
			lazy2[2*node]+=lazy2[node];
			lazy2[2*node+1]+=lazy2[node];
		}
		lazy2[node]=0;
	}
	if(i<=start && end<=j){
		return tree2[node];
	}
	int mid=(start+end)/2;
	return query2(2*node,start,mid,i,j)+query2(2*node+1,mid+1,end,i,j);
}
int main(){
	preprocess();
	int n;
	SI(n);
	int i,j;
	prod[0]=1;
	FOR(i,1,n){
		SI(ar[i]);
		SI(d[i]);
		prod[i]=d[i]*prod[i-1];
		if(prod[i]>=MOD)
			prod[i]%=MOD;
		SI(p[i]);
	} 
	build1(1,1,n);
	build2(1,1,n);
	int q,c;
	LL val;
	SI(q);
	while(q--){
		SI(c);
		SI(i);
		SI(j);
		if(c==0){
			val=query2(1,1,n,i,j);
			printf("%lld ",val);
			val=factorial(val);
			val*=query1(1,1,n,i,j);
			if(val>=MOD)
				val%=MOD;
			printf("%lld\n",val);
		}
		else{
			SL(val);
			update1(1,1,n,i,j,val);
			update2(1,1,n,i,j,val);
		}
	}
	return 0;
}
