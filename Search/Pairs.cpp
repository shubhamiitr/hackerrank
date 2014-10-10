#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,i,cnt=0,f,l;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    f=0;l=0;
    while(l<n)
    {
        if(a[l]-a[f]<k)
            l++;
        else if(a[l]-a[f]==k)
        {
            l++;
            f++;
            cnt++;
        }
        else
            f++;
    }
    printf("%d\n",cnt);
    return 0;
}
