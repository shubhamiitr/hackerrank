#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4,a,b,c,d,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&x1,&y1,&z1);
        scanf("%d%d%d",&x2,&y2,&z2);
        scanf("%d%d%d",&x3,&y3,&z3);
        scanf("%d%d%d",&x4,&y4,&z4);
        a=(y2-y1)*(z3-z1);
        b=(z1-z2)*(x3-x1);
        c=(x2-x1)*(y3-y1);
        d=a*x1+b*y1+c*z1;
        v=a*x4+b*y4+c*z4;
        if(d==v)
			printf("YES\n");
        else 
			printf("NO\n");
    }   
    return 0;
}
