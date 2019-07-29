#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int mod = 1e9+7;
const int MAXN = 1e5+7;

ll dp[2][3]={0};

int main()
{
	ll n,l,r;
	ll a=0,b=0,c=0;//0,1,2
	dp[0][0] = 1;
	cin>>n>>l>>r;
	a = (r-l+1)/3;
	b = (r-l+1)/3;
	c = (r-l+1)/3;
	if((r-l+1)%3==1){
		if(r%3==0) a++;
		else if(r%3==1) b++;
		else if(r%3==2) c++;
	}
	if((r-l+1)%3==2){
		if(r%3==0) a++,c++;
		else if(r%3==1) b++,a++;
		else if(r%3==2) c++,b++;
	}
	int i;
	for(i=1;i<=n;i++){
		dp[i%2][0]=(dp[(i-1)%2][0]*a+dp[(i-1)%2][1]*c+dp[(i-1)%2][2]*b)%mod;
		dp[i%2][1]=(dp[(i-1)%2][1]*a+dp[(i-1)%2][2]*c+dp[(i-1)%2][0]*b)%mod;
		dp[i%2][2]=(dp[(i-1)%2][2]*a+dp[(i-1)%2][0]*c+dp[(i-1)%2][1]*b)%mod;
	}
	i--;
	cout<<dp[i%2][0]<<endl;
	return 0;
}
