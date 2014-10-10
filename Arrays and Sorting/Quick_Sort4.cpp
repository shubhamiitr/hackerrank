#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int qcnt;
int icnt;
int partition(int l,int h) {
    int i,j,temp;
    i=j=l;
    while(i<h){
        if(a[i]<a[h]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j++;
            qcnt++;
        }
        i++;
    }
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    qcnt++;
    return j;
	
}
void quickSort(int l,int h)
{
	int mid=partition(l,h);
	if(l<(mid-1))
		quickSort(l,mid-1);
	if(h>(mid+1))
	quickSort(mid+1,h);
}
void insertionSort(int n){
	int i,j,k,val;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(b[j]>b[i])
				break;
		}
		val=b[i];
		for(k=i;k>j;k--){
			b[k]=b[k-1];
			icnt++;
		}
		b[j]=val;
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
	qcnt=0;
	quickSort(0,size-1);
	icnt=0;
	insertionSort(size);
	printf("%d\n",icnt-qcnt);
	return 0;
}
