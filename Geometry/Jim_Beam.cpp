#include<iostream>
#include<cstdio>
using namespace std;
struct Point
{
    long long x;
    long long y;
};
 
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
int orientation(Point p, Point q, Point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  
 
    return (val > 0)? 1: 2; 
}
 
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; 
}

int main()
{
	int t;
	long long x1,x2,y1,y2,xm,ym;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&xm,&ym);
		struct Point p1={0,0},q1={xm,ym};
		struct Point p2={x1,y1},q2={x2,y2};
		
		doIntersect(p1, q1, p2, q2)? printf("NO\n"): printf("YES\n");
	}
	return 0;
}
