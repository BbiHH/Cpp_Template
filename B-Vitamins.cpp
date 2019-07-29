#include<bits/stdc++.h>
using namespace std;

const int INF = 999999999;

int dp[8]={0};

int vita[1007] = {0};//富含的vita
int pay[1007] = {0}; //价格

char c[7];
int n;

int main()
{
	cin>>n;
	for(int i=0;i<8;i++)
		dp[i]=INF;
	for(int i=1;i<=n;i++){
		cin>>pay[i]>>c;
		for(int j=0;j<strlen(c);j++){
			if(c[j]=='A') vita[i] |=1;
			if(c[j]=='B') vita[i] |=2;
			if(c[j]=='C') vita[i] |=4;
		}
	}
	for(int i=1;i<=n;i++)
		dp[vita[i]] = min(dp[vita[i]],pay[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=7;j++)
			dp[j|vita[i]]=min(dp[j|vita[i]],dp[j]+pay[i]);
	if(dp[7]==INF)
		cout<<-1<<endl;
	else
		cout<<dp[7]<<endl;
	return 0;
}


