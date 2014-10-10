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
#define SD(x) scanf("%lf",&x)
#define PI(x) printf("%d ",x)
#define PL(x) printf("%lld ",x)
#define PD(x) printf("%lf ",x)
#define PIN(x) printf("%d\n",x)
#define PLN(x) printf("%lld\n",x)
#define PDN(x) printf("%lf\n",x)
#define PS printf(" ")
#define PN printf("\n")
#define BSCH(f,l,h) while(l<h){ int mid=(l+h)/2; if(f(mid)) h=mid; else l=mid+1;}
#define MOD 1000000007
#define MAX 1500
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
char p[MAX],q[MAX];
int d[MAX][MAX];
int main(){
	int t,s,j,i,pi,qi,l,psum,qsum,maxm;
	SI(t);
	while(t--){
		SI(s);
		SCA(p);
		SCA(q);
		maxm=-1;
		l=strlen(p);
		for(i=0;i<l;i++){
			for(j=0;j<l;j++)
				d[i][j]=(p[i]!=q[j]);
		}
		for(i=0;i<l;i++){
			psum=qsum=0;
			pi=-1;qi=-1;
			for(j=0;j+i<l;j++){
				psum+=d[j][i+j];
				qsum+=d[i+j][j];
				while(psum>s){
					pi++;
					psum-=d[pi][pi+i];
				}
				while(qsum>s){
					qi++;
					qsum-=d[qi+i][qi];
				}
				if(j-pi>maxm)
					maxm=j-pi;
				if(j-qi>maxm)
					maxm=j-qi;
			}
		}
		printf("%d\n",maxm);
	}
	return 0;
}
