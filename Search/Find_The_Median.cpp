#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int a[MAX];
int partition(int l,int h){
	int i=l,j=l,temp;
	int val=a[h];
	while(i<h){
		if(a[i]<val){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			j++;
		}
		i++;
	}
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	return j;
}
int n;
int selection(int kth){
	int pivot;
	int l=0,h=n-1;
	while(1){
		pivot=partition(l,h);
		if(pivot==kth){
			return a[pivot];
		}
		else if(pivot>kth)
			h=pivot-1;
		else
			l=pivot+1;
	}
	return a[l];
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",selection(n/2));
	return 0;
}
