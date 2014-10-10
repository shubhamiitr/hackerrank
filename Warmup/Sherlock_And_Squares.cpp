#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000
int n;
int a[100000];
void preprocess(){
    int i;
    for(i=0;i*i<MAX;i++){
        a[i]=i*i;
    }
    a[i]=i*i;
    n=i+1;
}
int bsearch(int x){
    int l=0,h=n-1,mid;
    while(l<h){
        mid=l+(h-l)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]>x)
			h=mid-1;
        else{
            if(a[mid+1]>x)
                return mid;
            else
                l=mid+1;
        }
    }
    return l;
}
int main() {
    int t,m,n;
    preprocess();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        printf("%d\n",bsearch(n)-bsearch(m-1));
    }
    return 0;
}
