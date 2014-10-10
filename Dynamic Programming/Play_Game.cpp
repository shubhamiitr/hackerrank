#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
#define MAX 100005
ll dp[MAX];
int a[MAX];
ll sm[MAX];

int main() 
{ 
    int t,n,i;
    scanf("%d",&t);
    while(t--) 
    { 
        scanf("%d",&n);
        for(i=n; i>=1; i--)
			scanf("%d",&a[i]);
        sm[0]=0;
        for(i=1; i<=n; i++) 
            sm[i]=sm[i-1]+a[i];
        dp[0]=0;
        dp[1]=a[1];
        dp[2]=dp[1]+a[2];
        dp[3]=dp[2]+a[3]; 
        for(i=4; i<=n; i++)
            dp[i]=max(sm[i-1]-dp[i-1]+a[i],max(sm[i-2]-dp[i-2]+a[i]+a[i-1],sm[i-3]-dp[i-3]+a[i]+a[i-1]+a[i-2])); 
        printf("%lld\n",dp[n]);
    }
    return 0; 
}
