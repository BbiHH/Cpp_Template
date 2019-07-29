#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int MAXN = 1e5+7;
const int INF = -1e9-7;


struct tree
{
	int x; //坐标
	int h; //高度
}t[MAXN];

int n;


ll solve()
{
	ll now = t[1].x;
	ll ans;
	for(int i=2;i<n;i++)
	{
		if(now<t[i].x-t[i].h)
		{
			++ans;
			now = t[i].x;
		}
		else if(t[i].x+t[i].h<t[i+1].x)
		{
			++ans;
			now = t[i].x+t[i].h;
		}
		else
			now = t[i].x;
	}
	ans+=2;
	return ans;
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].x>>t[i].h;
	cout<<solve()<<endl;
}
