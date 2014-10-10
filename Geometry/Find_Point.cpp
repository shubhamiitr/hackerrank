#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d\n",2*c-a,2*d-b);
	}
	return 0;
}
