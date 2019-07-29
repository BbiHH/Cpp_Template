#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5007;

char s[MAXN];

int dp[MAXN][3]={0};

int main()
{
	cin>>s;
	int n = strlen(s);
	if(s[0]=='a') dp[0][0] =1;
	if(s[0]=='b') dp[0][1] =1;
	for(int i=1;i<n;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		dp[i][2]=dp[i-1][2];
		if(s[i]=='a'){
			dp[i][0] = dp[i-1][0]+1;
			dp[i][2] = max(dp[i-1][2]+1,dp[i-1][1]+1);
		}
		else
			dp[i][1] = max(dp[i-1][1]+1,dp[i-1][0]+1);
	}
	int ans = 0;
	for(int i=0;i<3;i++) ans = max(ans,dp[n-1][i]);
	cout<<ans<<endl;
}


