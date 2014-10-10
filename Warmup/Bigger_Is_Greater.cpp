#include<bits/stdc++.h>
using namespace std;
char s[100];
int main()
{
	int t,l;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		l=strlen(s);
		if(next_permutation(s,s+l)){
			printf("%s\n",s);
		}
		else
			printf("no answer\n");
	}
	return 0;
}
