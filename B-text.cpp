#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+7;

int dp[MAXN]={0};

char c[MAXN];

int main()
{
	scanf("%s",c);
	dp[0]=1;
	int a1=0;
	int a2=0;
	int n = strlen(c);
	for(int i=1;i<n;i++){
			for(int j=0;i+j<n && c[i-1]==c[i+j] ; j++)
				a2 = j;
			dp[i+a2] = dp[i-1]+max(a1,a2);
			a1 = a2 ;
	}
	cout<<dp[n-1]<<endl;
}
