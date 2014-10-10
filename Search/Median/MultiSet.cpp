#include<bits/stdc++.h>
using namespace std;
multiset<int> minset,maxset; 
/** 
		0<=|minset|-|maxset|<=1
 **/
multiset<int> :: iterator it1,it2;
int main(){
	int n;
	scanf("%d",&n);
    char c[10];
	int i;
    int val;
    long long x;
	for(i=0;i<n;i++){
		scanf("%s%d",c,&val);
		if(c[0]=='a'){
            if(minset.empty())
				minset.insert(val);
			else if(minset.size()==maxset.size()){
				maxset.insert(val);
				minset.insert(*maxset.begin());
				maxset.erase(maxset.begin());
			}
			else{
					minset.insert(val);
					maxset.insert(*minset.rbegin());
					minset.erase(minset.find(*minset.rbegin()));
			}
		}
		else{
			it1=minset.find(val);
			it2=maxset.find(val);
			if((it1==minset.end()) && (it2==maxset.end())){
				printf("Wrong!\n");
				continue;
			}
			if(minset.size()==maxset.size()){
				if(it2!=maxset.end()){
					maxset.erase(it2);
				}
				else{
					minset.erase(it1);
					minset.insert(*maxset.begin());
					maxset.erase(maxset.begin());
				}
			}
			else if(it1!=minset.end()){
				minset.erase(it1);
			}
			else{
				maxset.erase(it2);
				maxset.insert(*minset.rbegin());
				minset.erase(minset.find(*minset.rbegin()));
			}
		}
		if(minset.empty())
			printf("Wrong!\n");
		else if(minset.size()==maxset.size()){
			x=(*minset.rbegin());
            x+=(*maxset.begin());
			if(x&1)
				printf("%lld.5\n",x/2);
			else
				printf("%lld\n",x/2);
		}
		else{
			printf("%d\n",*minset.rbegin());
		}
	}
	return 0;
}
