#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define MAX 1000001
int stk[MAX],top;
int lft[MAX];
int rht[MAX];
int a[MAX],n;
int tree[MAX];
vector<int> r[MAX];
void update(int idx,int val){
	while(idx<MAX){
		tree[idx]+=val;
		idx+=(idx& -idx);
	}
}
int read(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	top=0;
	for(i=1;i<=n;i++){
		while(top>0 && a[i]>a[stk[top-1]]) 
			top--;
		lft[i]=top ? stk[top-1]:0;
		stk[top++]=i;
	}
	top=0;
	for(i=n;i>0;i--){
		while(top>0 && a[i]<a[stk[top-1]])
			top--;
		rht[i]=top ? stk[top-1]:n+1;
		stk[top++]=i;
	}
	for(i=1;i<MAX;i++)
		tree[i]=0;
	ll ans=0;
	vector<int>::iterator it;
	for(i=n;i>=1;i--){
		for(it=r[i].begin();it!=r[i].end();it++){
			update(*it,-1);
		}
		update(i,1);
		r[lft[i]].push_back(i);
		ans+=read(rht[i]-1);
	}
	printf("%lld\n",ans);
	return 0;
}
