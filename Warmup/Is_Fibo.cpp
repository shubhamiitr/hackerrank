#include<bits/stdc++.h>
using namespace std;
#define MAX 1E10
typedef long long ll;
map<ll,bool> isFibo;
void preprocess(){
	ll a=0,b=1,c;
	isFibo[a]=true;
	isFibo[b]=true;
	while(b<=MAX){
		c=b;
		b=a+b;
		a=c;
		isFibo[b]=true;
	}
}
int main(){
	preprocess();
	int t;
	ll n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(isFibo[n])
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
	}
	return 0;
}
