#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	int t,l,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&b);
		printf("%d\n",l/gcd(l,b)*b/gcd(l,b));
	}
	return 0;
}
	
