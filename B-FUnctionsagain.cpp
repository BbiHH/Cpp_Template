#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 1e5+7;

//前n个数中最大的func
ll dp[2];

int a[MAXN];
int n;

ll x[MAXN];

ll init()
{
	for(int i=1;i<=n;i++)
		x[i]=max(a[i],a[i-1])-min(a[i],a[i-1]);
	ll ans1 = 0LL,ans2 = 0LL;
	for(int i=1;i<=n;i++){
		if(dp[0]<0) dp[0] = 0;
		if(dp[1]<0) dp[1]= 0;
		if(i&1){
			dp[0]+=x[i];
			dp[1]-=x[i];
		}
		else {
			dp[0]-=x[i];
			dp[1]+=x[i];
		}
		ans1 = max(ans1,dp[0]);
		ans2 = max(ans2,dp[1]);
	}
	return max(ans1,ans2);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<init()<<endl;
}
	





