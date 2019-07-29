#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int t[1007];
int _rank[1007]={0};
void func1(int n)
{
    for(int i=1; i<=n; i++)
        t[i]=i;
}

int Find(int i)
{
    if(t[i]==i)
        return i;
    else
        return t[i]=Find(t[i]);
}

void unite(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
    return ;
    if(_rank[x]<_rank[y])
        t[x]=y;
    if(_rank[x]>_rank[y])
        t[y]=x;
    else
    {
        t[y]=x;
        _rank[x]++;
    }
}

int main()
{
    int N, M ;
    while(cin>>N)
    {
        if(N==0)
            return 0;
        scanf("%d",&M);
        int ans=0;
        func1(N);
        memset(_rank,0,sizeof(_rank))
        for(int i=0; i<M; i++)
        {
            int a, b;
            scanf("%d%d",&a,&b);
            unite(a,b);
        }
        for(int i=1; i<=N; i++)
            for(int j=i; j<=N; j++)
                if(Find(i)!=Find(j))
                {
                    unite(i,j)
                    ans++;
                }
        cout<<ans<<endl;
    }
}
