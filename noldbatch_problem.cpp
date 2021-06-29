#include<bits/stdc++.h>

using namespace std;

int main(){
	int i ,j ,n ,k ,r=0;
	cin>>n>>k;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int s=i*i;s<=n;s+=i){
				prime[s]=false;
			} 
		}
	}
	for(i=2;i<=n;i++){
		if(prime[i]==true){
			for(j=i+1;j<=n;j++){ 
				if(prime[j]==true){
					break;
				}
			}
			if(i+j+1<=n && prime[i+j+1]==true){
				r++;
			}
		}
	}
	if(r>=k){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
