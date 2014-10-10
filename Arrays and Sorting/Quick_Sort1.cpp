#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
void partition() {
    int i,j,t,n=a.size();
    i=j=n-1;
    while(i>0){
        if(a[i]>a[0]){
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
    j=0;
    for(i=0;i<n;i++){
		if(b[i]<t){
			a[j++]=b[i];
		}
	}
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(void) {
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);
		b.push_back(x); 
	}
	partition();
	return 0;
}
