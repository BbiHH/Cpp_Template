#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

long long int w[3][MAXN]={0};
long long int d[3][MAXN]={0LL};
int n ;

void init()
{
        for(int i=1;i<=n;i++){
		d[1][i]=max(d[2][i-1]+w[1][i],d[1][i-1]);
		d[2][i]=max(d[1][i-1]+w[2][i],d[2][i-1]);
	}
}
int main()
{
        cin>>n;
        for(int i=1;i<3;i++)
        for(int j=1;j<=n;j++)
                cin>>w[i][j];
        init();
        cout<<max(d[1][n],d[2][n])<<endl;
}
