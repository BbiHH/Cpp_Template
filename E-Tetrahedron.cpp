#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int mod = 1e9+7;

ll matrix[4][4]={0LL};  //矩阵
ll res[4][4] = {0LL};

ll n; 

//矩阵相乘
void multi(ll a[][4],ll b[][4],int n)
{
	ll tmp[4][4] = {0LL};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				tmp[i][j] = (tmp[i][j]%mod+(a[i][k]*b[k][j])%mod)%mod;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j] = tmp[i][j];
}


void power(ll a[][4],ll N)
{
	for(N;N;N>>=1){
		if(N&1)  multi(a,res,4);
	       multi(res,res,4);	
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(i!=j)  matrix[i][j] = 1LL , res[i][j] = 1LL;
	power(matrix,n-1);
	ll ans = matrix[0][0]%mod;
	cout<<ans<<endl;
}
