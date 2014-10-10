#include<bits/stdc++.h>
using namespace std;
#define MAX 500
char s[MAX];
int a[MAX][MAX];
int main(){
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			a[i][j]=s[j]-'0';
		}
	}
	int val,cnt=0,maxval=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			val=0;
			for(k=0;k<m;k++){
				val+=a[i][k]|a[j][k];
			}
			if(val>maxval){
				maxval=val;
				cnt=1;
			}
			else if(val==maxval)
				cnt++;
		}
	}
	printf("%d\n%d\n",maxval,cnt);
	return 0;
}
