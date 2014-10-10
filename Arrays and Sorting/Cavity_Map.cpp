#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int a[MAX][MAX];
int b[MAX][MAX];
char s[MAX]; 
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<n;j++){
			a[i][j]=b[i][j]=s[j]-'0';
		}
	}
	for(i=1;i<n-1;i++){
		for(j=1;j<n-1;j++){
			if(a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1])
				b[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i][j]==0)
				printf("X");
			else
				printf("%d",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
