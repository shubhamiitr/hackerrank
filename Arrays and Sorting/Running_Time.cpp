#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,cnt,val,n;
	int a[1001];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(a[j]>a[i]){
				val=a[i];
				for(k=i-1;k>=j;k--){
					a[k+1]=a[k];
					cnt++;
				}
				a[j]=val;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
