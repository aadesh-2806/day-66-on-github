#include<iostream>

using namespace std;

int main(){
	int i,n,m,k=0;
	cin>>n>>m;
	if(m>n){
		i=m;
		m=n;
		n=i;
	}
	while(n-m!=0){
		n=n-m;
		if(m>n){
			i=m;
			m=n;
			n=i;
		}
		k++;
	}
	cout<<k+1;
}
