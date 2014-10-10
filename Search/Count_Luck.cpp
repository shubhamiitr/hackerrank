#include<bits/stdc++.h>
using namespace std;
#define MAX 100 
char a[MAX][MAX];
int vis[MAX][MAX];
int par[MAX][MAX][2];
int m,n;
int X[]={1,-1,0,0};
int Y[]={0,0,-1,1};
bool valid(int r,int c){
	return r>=0 && r<n && c>=0 && c<m && a[r][c]!='X';
}
void dfs(int r,int c,int pr,int pc){
	if(!valid(r,c))
		return;
	if(vis[r][c]==2)
		return;
	vis[r][c]=1;
	par[r][c][0]=pr;
	par[r][c][1]=pc;
	for(int i=0;i<4;i++){
		if((r+X[i])!=pr || (c+Y[i]!=pc)){
			dfs(r+X[i],c+Y[i],r,c);
		}
	}
	vis[r][c]=2;
}
int main(){
	int t,cnt,i,j,k,r,c,sr,sc,dr,dc;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof vis);
		for(i=0;i<n;i++){
			scanf("%s",a[i]);
			for(j=0;j<m;j++){
				if(a[i][j]=='M'){
					sr=i;
					sc=j;
				}
				if(a[i][j]=='*'){
					dr=i;
					dc=j;
				}
			}
		}
		scanf("%d",&k);
		dfs(sr,sc,-1,-1);
		/*for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				printf("%d:%d ",par[i][j][0],par[i][j][1]);
			}
			printf("\n");
		}
		printf("\n");*/
		r=par[dr][dc][0];
		c=par[dr][dc][1];
		while(r!=sr || c!=sc){
			cnt=0;
			for(i=0;i<4;i++){
				int rr=r+X[i],cc=c+Y[i];
				if(valid(rr,cc)){
					cnt++;
				}
			}
			if(cnt>2) //One will the path from where the M is coming
				k--;
			dr=par[r][c][0];
			dc=par[r][c][1];
			r=dr;
			c=dc;
		}
		cnt=0;
		for(i=0;i<4;i++){
			int rr=r+X[i],cc=c+Y[i];
			if(valid(rr,cc)){
				cnt++;
			}
		}
		if(cnt>1)
			k--;
		printf("%s\n",k==0 ?"Impressed":"Oops!");
	}
	return 0;
}
