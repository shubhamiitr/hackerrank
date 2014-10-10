#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int arr[MAX];
int P, Q;
int answer;
int check(int x)
{
	int ret=INT_MAX;
	for(int i=0;i<n;i++) 
		ret =min(ret,abs(x-arr[i]));
	return ret;
}
void limits(int x)
{
	if(x<P || x>Q) 
		return;
	if(check(x)>check(answer)) 
		answer=x;   
}
int main()
{
	scanf("%d",&n );
	for(int i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	scanf("%d%d",&P,&Q);
	answer=P;
	limits(P);	 
	limits(Q);
	int i,j;
	for(i=0;i<n;i++) 
		for(j=i+1;j<n;j++) 
			limits((arr[i]+arr[j])/2);
	printf( "%d\n",answer );
	return 0;
}
