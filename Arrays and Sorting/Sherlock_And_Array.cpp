#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int a[MAX];
int main(){
	int t,i,n,left,right,fg;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		right=0;
		left=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			right+=a[i];
		}
		fg=0;
		for(i=0;i<n;i++){
			right-=a[i];
			if(left==right){
				fg=1;
				break;
			}			
			left+=a[i];
		}
		if(fg==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
