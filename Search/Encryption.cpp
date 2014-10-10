#include<bits/stdc++.h>
using namespace std;
char a[9][9];
char s[81];
int main(){
	scanf("%s",s);
	int l=strlen(s);
	int r=floor(sqrt(l));
	int c=(l+r-1)/r;
	while(c>(r+1)){
		r++;
		c=(l+r-1)/r;
	}
	int i,j,k;
	k=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(k<l)
				a[i][j]=s[k++];
			else
				a[i][j]='-';
		}
	}
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			if((a[j][i])!='-')
				printf("%c",a[j][i]);
		}
		printf(" ");
	}
	return 0;
}
