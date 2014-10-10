#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,r,k,x,y,cnt;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&r,&k);
		cnt=0;
		for(x=1;x*x<=r;x++){
			y=floor(sqrt(r-x*x));
			if((x*x+y*y)==r)
				cnt+=4;
		}
		if(cnt<=k)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}
