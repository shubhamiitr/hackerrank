#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k,pos;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		k++;
		pos=1;
		while(pos<=n){
			if(pos&1){
				if(n-pos/2==k){
					printf("%d\n",pos-1);
					break;
				}
			}
			else{
				if(pos==2*k){
					printf("%d\n",pos-1);
					break;
				}
			}
			pos++;
		}
	}
	return 0;
}
