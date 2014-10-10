#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long long r1,r2;
    long long a1x,a2x,a1y,a2y,a1z,a2z;
    long long x1,y1,z1,x2,y2,z2;
    double a,b,c,det;
    while(t--)
    {
        scanf("%lld%lld",&r1,&r2);
        scanf("%lld%lld%lld",&x1,&y1,&z1);
        scanf("%lld%lld%lld",&a1x,&a1y,&a1z);
        scanf("%lld%lld%lld",&x2,&y2,&z2);
        scanf("%lld%lld%lld",&a2x,&a2y,&a2z);
        a=(a1x-a2x)*(a1x-a2x)+(a1y-a2y)*(a1y-a2y)+(a1z-a2z)*(a1z-a2z);
        b=4.*((x1-x2)*(a1x-a2x) + (y1-y2)*(a1y-a2y) + (z1-z2)*(a1z-a2z));
        c=4.*((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) - (r1+r2)*(r1+r2));
        det=b*b-4*a*c;
        if(det<0)
			printf("NO\n");
        else
        {
            if(sqrt(det)<b)
				printf("NO\n");
            else 
				printf("YES\n");
        }
    }
    return 0;
}
