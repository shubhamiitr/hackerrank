#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	int a[26],b[26];
	cin>>s1>>s2;
	int i,l1,l2;
	for(i=0;i<26;i++){
		a[i]=0;
		b[i]=0;
	}
	l1=s1.length();
	l2=s2.length();
	for(i=0;i<l1;i++){
		a[s1[i]-'a']++;
	}
	for(i=0;i<l2;i++){
		b[s2[i]-'a']++;
	}
	int ans=0;
	for(i=0;i<26;i++){
		ans+=abs(b[i]-a[i]);
	}
	printf("%d\n",ans);
	return 0;
}
