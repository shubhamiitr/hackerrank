#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define MAX 5000000
#define N 314159
char a[MAX];
char b[MAX];
ll pow2[MAX];
ll t[MAX];
void preprocess(){
	pow2[0]=1;
	int i;
	for(i=1;i<MAX;i++){
		pow2[i]=pow2[i-1]*2;
		if(pow2[i]>=MOD)
			pow2[i]%=MOD;
	}
}
int main(){
	scanf("%s%s",a,b);
	int i,l;
	preprocess();
	l=strlen(a);
	char c;
	for(i=0;i<l/2;i++){
		c=a[i];
		a[i]=a[l-1-i];
		a[l-1-i]=c;
	}
	for(i=l;i<MAX;i++)
		a[i]='0';
	l=strlen(b);
	for(i=0;i<l/2;i++){
		c=b[i];
		b[i]=b[l-1-i];
		b[l-1-i]=c;
	}
	for(i=l;i<MAX;i++)
		b[i]='0';
	l=0;
	for(i=0;i<MAX;i++){
		if(b[i]=='1'){
			l++;
		}
		if(i>N){
			if(b[i-N-1]=='1')
				l--;
		}
		t[i]=l;
	}
	ll ans=0;
	for(i=0;i<MAX;i++){
		if(a[i]=='1'){
			ans+=(N+1-t[i])*pow2[i];
			if(ans>=MOD)
				ans%=MOD;
		}
		else{
			ans+=pow2[i]*t[i];
			if(ans>=MOD)
				ans%=MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
