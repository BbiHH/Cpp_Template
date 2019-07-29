#include<bits/stdc++.h>

using namespace std;

const int MAXN = 10001;

int prime[MAXN]={0};

int is_prime[MAXN]={0};

int cnt = 0;
void init()
{
	for(int i=2;i<MAXN;i++)
		if(is_prime[i]==0){
			for(int j=2*i;j<MAXN;j+=i)
				is_prime[j]=1;
		}
	for(int i=2;i<MAXN;i++)
		if(is_prime[i]==0)
			prime[cnt++] = i;
}

int main()
{
	int n;
	init();
	while(cin>>n)
	{
		if(n==0)
			break;
		int sum =0;
		int ans =0;
		for(int i=0;i<cnt;i++){
			sum = 0;
			for(int j=i;j<cnt;j++){
				sum+=prime[j];
				if(sum==n){
					ans++;
					break;
				}
				else if(sum>n)
					break;
			}
			}
		cout<<ans<<endl;
		}
	
		return 0 ;
}
					
		

