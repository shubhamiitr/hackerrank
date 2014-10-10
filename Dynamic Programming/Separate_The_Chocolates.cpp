#include<bits/stdc++.h>
using namespace std;
#define MAX 9
int a[MAX][MAX];
int b[MAX][MAX];
int vis[MAX][MAX];
char s[MAX][MAX];
int n,m;
bool check1(){
	int i,j;
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(b[i][j]==b[i-1][j] && b[i][j]==b[i][j-1] && b[i][j]==b[i-1][j-1])
				return false;
		}
	}
	return true;
}
void dfs(int i,int j,int k){
	if(i>=n || j>=m || i<0 || j<0)
		return;
	if(vis[i][j]==k || (b[i][j]!=k))
		return;
	vis[i][j]=k;
	dfs(i+1,j,k);
	dfs(i-1,j,k);
	dfs(i,j+1,k);
	dfs(i,j-1,k);
}
bool check2(){
	int i,j,r=-1,c=-1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(b[i][j]!=b[0][0]){
				r=i;
				c=j;
			}
			vis[i][j]=-1;
		}
	}
	dfs(0,0,b[0][0]);
	if(r>=0 && c>=0)
		dfs(r,c,b[r][c]);
	/*for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",vis[i][j]);
		}
		printf("\n");
	}*/
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(vis[i][j]<0)
				return false;
	return true;
}
int main(){
	int k;
	scanf("%d%d%d",&n,&m,&k);
	int i,j;
	unsigned long long p,q,x;
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
		for(j=0;j<m;j++){
			if(s[i][j]=='T')
				a[i][j]=0;
			else if(s[i][j]=='D')
				a[i][j]=1;
			else
				a[i][j]=-1;
		}
	}
	x=1;
	for(i=0;i<n;i++)
		x<<=m;
	int ans=0;
	int cnt[2];
	bool fg;
	for(p=0;p<x;p++){
		i=0;
		j=0;
		q=p;
		cnt[0]=cnt[1]=0;
		fg=true;
		while(q){
			b[i][j]=(q&1);
			cnt[b[i][j]]++;
			if(b[i][j]+a[i][j]==1){
				fg=false;
				break;
			}
			q/=2;
			j++;
			if(j==m){
				i++;
				j=0;
			}
		}
		if(fg==false)
			continue;
		while(i<n){
			b[i][j]=0;
			cnt[0]++;
			if(b[i][j]+a[i][j]==1){
				fg=false;
				break;
			}
			j++;
			if(j==m){
				i++;
				j=0;
			}
		}
		if(fg==false){
			continue;
		}
		if(abs(cnt[0]-cnt[1])>k){
			continue;
		}
		if(check1()==false){
			continue;
		}
		if(check2())
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
