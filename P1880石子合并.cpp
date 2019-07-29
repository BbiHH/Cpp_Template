#include<bits/stdc++.h>

using namespace std;

int dp1[205][205]={0};
int dp2[205][205]={0};

int d[205]={0};
int s[205];

const int INF = 99999999;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i+n]=s[i];
	}
	for(int i=1;i<=n+n;i++)
		d[i]=d[i-1]+s[i];
	for(int p=1;p<n;p++)
		for(int i=1,j=i+p;i<2*n&&i+p<2*n;i++,j=i+p){
			dp2[i][j] = INF;
			for(int k=i;k<j;k++){
				dp1[i][j] = max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+d[j]-d[i-1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+d[j]-d[i-1]);
			}
		}
        int minl=999999999;
       int maxl=0;	
    for(int i=1;i<=n;i++)  
    {  
        maxl=max(maxl,dp1[i][i+n-1]);  
        minl=min(minl,dp2[i][i+n-1]);  
    }  
    cout<<minl<<'\n'<<maxl<<endl;
	return 0;
}
