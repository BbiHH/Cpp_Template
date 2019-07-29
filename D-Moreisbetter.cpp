#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7+7;
int t[MAXN];
int _rank[MAXN]={0};
int M = 0;

void func1(int n)
{
    for(int i=1; i<=n; i++){
        t[i]=i;
	_rank[i]=1;
    }
}

int Find(int i)
{
    if(t[i]==i)
        return i;
    else
        return t[i]=Find(t[i]);
}

void unite(int nx,int ny)
{
    int x = Find(nx);
    int y = Find(ny);
    if(x!=y)
    {
	    t[x]=y;
	    _rank[y]+=_rank[x];
	    if(_rank[y]>M) M = _rank[y];
    }
}
int main()
{
    int N;
    while(cin>>N)
    {
        M = 0;
        func1(MAXN);
        for(int i=0; i<N; i++)
        {
            int a, b;
            scanf("%d%d",&a,&b);
            unite(a,b);
        }
        cout<<M<<endl;
    }
}
