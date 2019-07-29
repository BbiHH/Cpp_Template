#include<bits/stdc++.h>

using namespace std;

const int mod = 1e8;

int dp[2][103][103]={0};

int main()
{
        int n1,n2,k1,k2;
        scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
        for(int i=0;i<=k1;i++) dp[0][i][0] = 1;
        for(int i=0;i<=k2;i++) dp[1][0][i] = 1;
        for(int i=1;i<=n1;i++)
                for(int j=1;j<=n2;j++){
                        for(int k=1;k<=min(k1,i);k++)
                                dp[0][i][j] = (dp[0][i][j]+dp[1][i-k][j])%mod;
                        for(int k=1;k<=min(k2,j);k++)
                                dp[1][i][j] = (dp[1][i][j]+dp[0][i][j-k])%mod;
                }
        cout<<(dp[1][n1][n2]+dp[0][n1][n2])%mod<<endl;
        return 0;
}
