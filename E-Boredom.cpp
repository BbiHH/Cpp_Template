#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

typedef long long int ll;

ll n[MAXN]={0LL};

ll dp[2][MAXN]={0LL};


int main()
{
	ll m;
	cin>>m;

	ll o;
	ll t=0LL;
	for(ll i=0;i<m;i++){
		cin>>o;
		t = max(t,o);
		n[o]+=1;
	}
	dp[0][1] = 1*n[1];
	dp[1][1] = 2*n[2];
	for(ll i=1;i<=t;i++)
	{
		if(i&1)
		dp[0][i] = max(dp[0][i-2]+i*n[i],dp[1][i-1]);
		else
		dp[1][i] = max(dp[1][i-2]+i*n[i],dp[0][i-1]);
	}
	ll ans = max(dp[0][t],dp[1][t]);
	cout<<ans<<endl;
}


