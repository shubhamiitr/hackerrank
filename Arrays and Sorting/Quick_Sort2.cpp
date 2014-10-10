#include<bits/stdc++.h>
using namespace std;
vector <int> a;
vector <int> b;
int partition(int l,int h) {
    int i,j,t;
    i=j=h;
    while(i>l){
        if(a[i]>a[l]){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            j--;
        }
        i--;
    }
    t=a[i];
    a[i]=a[j];
    a[j]=t;
    j=l;
    for(i=l;i<=h;i++){
		if(b[i]<t){
			a[j++]=b[i];
		}
	}
	for(i=l;i<=h;i++){
		b[i]=a[i];
	}
    return j;
	
}
void quickSort(int l,int h)
{
	int i;
	int mid=partition(l,h);
	//cout<<l<<" "<<h<<" : "<<mid<<endl;
	if(l<mid)
		quickSort(l,mid-1);
	if(h>mid)
	quickSort(mid+1,h);
	if(l<h){
		for(i=l;i<=h;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}
int main(void) {
	int size,i,x;
	scanf("%d",&size);
	for(i=0;i<size; i++) {
		scanf("%d",&x);
		a.push_back(x); 
		b.push_back(x);
	}
	quickSort(0,size-1);
	return 0;
}
