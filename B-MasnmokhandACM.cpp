#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int dp[2010][2010]={0};

int n,k;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		dp[1][i]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int z=0;j+z<=n;z+=j)
				dp[i][j+z]=(dp[i][j+z]+dp[i-1][j])%mod;
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans = (ans+dp[k][i])%mod;
	cout<<ans<<endl;
	return 0;
}
