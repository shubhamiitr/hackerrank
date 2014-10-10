#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
typedef long long ll;
int a[MAX];
int b[MAX];
ll tree[MAX];
int n;
void input(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
}
void initialize(){
	for(int i=0;i<MAX;i++)
		tree[i]=0;
}
void index(){
	sort(b,b+n);
	int rank;
	for(int i=0;i<n;i++){
		rank=int(lower_bound(b,b+n,a[i])-b);
		a[i]=rank+1;
	}
}
void update(int idx,int val){
	while(idx<MAX){
		tree[idx]+=val;
		idx+=(idx& -idx);
	}
}
ll read(int idx){
	ll sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx& -idx);
	}
	return sum;
}
ll solve(){
	input();
	initialize();
	index();
	ll ans=0;
	for(int i=n-1;i>=0;i--){
		ans+=read(a[i]-1);
		update(a[i],1);
	}	
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		printf("%lld\n",solve());
	}
	return 0;
}
