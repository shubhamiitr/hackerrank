#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int a[MAX];
int ans[MAX];
int main(){
	int n,i,s=0,x,val,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	for(x=1;x*x<=s;x++)
	if(s%x==0){
		val=0;
		for(i=0;i<n;i++){
			val+=a[i];
			if(val==x)
				val=0;
			else if(val>x)
				break;
		}
		if(i==n && val==0)
			ans[k++]=x;
		if(x*x==s)
			break;
		val=0;
		for(i=0;i<n;i++){
			val+=a[i];
			if(val==(s/x))
				val=0;
			else if(val>(s/x))
				break;
		}
		if(i==n && val==0)
			ans[k++]=(s/x);	
	}
	sort(ans,ans+k);
	for(i=0;i<k;i++)
		printf("%d ",ans[i]);
	return 0;
}
