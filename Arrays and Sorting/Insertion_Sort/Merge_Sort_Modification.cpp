#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
typedef long long ll;
int a[MAX];
int temp[MAX];
ll merge(int l,int mid,int r){
	int i,j,k;
	ll inv=0;
	i=l;j=mid+1;k=l;
	while(i<=mid && j<=r){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
			inv+=mid-i+1;
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];
	for(i=l;i<=r;i++){
		a[i]=temp[i];
	}
	return inv;
}
ll merge_sort(int l,int r){
	ll inv=0;
	int mid;
	if(l<r){
		mid=(l+r)/2;
		inv+=merge_sort(l,mid);
		inv+=merge_sort(mid+1,r);
		inv+=merge(l,mid,r);
	}
	return inv;
}
int main(){
	int t,n,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("%lld\n",merge_sort(0,n-1));
	}
	return 0;
}
