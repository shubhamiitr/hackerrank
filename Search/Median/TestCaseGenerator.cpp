#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(){
	freopen("input.txt","w",stdout);
	cout<<MAX<<endl;
	int x,y;
	int n;
	for(int i=0;i<MAX;i++){
		x=rand()%2;
		y=rand()%2;
		n=rand()%(INT_MAX);
		if(y)
			n*=-1;
		if(x){
			printf("a %d\n",n);
		} 
		else{
			printf("r %d\n",n);
		}
	}
	fclose(stdout);
}
