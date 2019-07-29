#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+7;

int dp[MAXN]={0};

struct something
{
	int w; //重量
	int v; //价值
}it[MAXN];

int p,h,k; // 重量p,价值h,个数k

int main()
{
	int n; //物品个数
	int W; //背包容量
	cin>>n>>W;
	int index = 0;
	for(int i=1;i<=n;i++){
		int c = 1;
		cin>>p>>h>>k;
		while(k-c>0){
			k -= c;
			it[++index].w = c*p;
			it[index].v = c*h;
			c*=2;
		}
		it[++index].w = p*k;
		it[index].v = h*k;
	}
	for(int i=1;i<=index;i++)
		for(int j=W;j>=it.w[i];j--)
			dp[j] = max(dp[j-it.w[i]]+it.v[i] , dp[j]);
	cout<<dp[W]<<endl;
}

