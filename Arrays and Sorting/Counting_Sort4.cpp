#include<bits/stdc++.h>
using namespace std;
vector<string> v[100];
vector<string>::iterator it;
int main(){
	int n,i,x;
	cin>>n;
	for(i=0;i<n;i++){
		string s;
		cin>>x>>s;
		if(2*i<n)
			v[x].push_back("-");
		else
			v[x].push_back(s);
	}
	for(i=0;i<100;i++){
		for(it=v[i].begin();it!=v[i].end();it++)
			cout<<*it<<" ";
	}
	return 0;
}
