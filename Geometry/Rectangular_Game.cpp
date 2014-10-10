#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b;
	int x=INT_MAX,y=INT_MAX;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		x=min(x,a);
		y=min(y,b);
	}
	printf("%lld\n",((long long)x)*y);
	return 0;
}
