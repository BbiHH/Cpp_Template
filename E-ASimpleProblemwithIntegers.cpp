#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN = 1e5+7;

#define LS(a) a<<1
#define RS(a) a<<1|1
typedef long long int ll ;

ll a[MAXN];
ll d[4*MAXN];
ll b[4*MAXN]={0};

void build(ll s,ll t,ll p)
{
        if(s==t){
                d[p] = a[s];
                return ;
        }
        int m = (s+t)>>1;
        build(s,m,LS(p)), build(m+1,t,RS(p));
        d[p] = d[LS(p)]+d[RS(p)];
}

ll getsum(ll l,ll r,ll s,ll t,ll p)
{
        if(l<=s&&t<=r)
                return d[p];
        ll sum = 0LL;
        ll m = (s+t)>>1;
        if(b[p]){
                  d[p*2]+=b[p]*(m-s+1) , d[p*2+1]+=b[p]*(t-m);//更新值
                  b[p*2]+=b[p] , b[p*2+1]+=b[p];//标记下传
                  b[p] = 0;//清空标记
         }

        if(l<=m) sum+=getsum(l,r,s,m,LS(p));
        if(r>m)  sum+=getsum(l,r,m+1,t,RS(p));

        return sum ;
}

void update(ll l,ll r,ll c,ll s,ll t,ll p)
{
        if(l<=s&&t<=r){
                d[p]+=c*(t-s+1), b[p]+=c;
                return ;
        }
        ll m = (s+t)>>1;
        if(b[p] && s!=t){
                  d[p*2]+=b[p]*(m-s+1) , d[p*2+1]+=b[p]*(t-m);//更新值
                  b[p*2]+=b[p] , b[p*2+1]+=b[p];//标记下传
                  b[p] = 0;//清空标记
          }
        if(l<=m) update(l,r,c,s,m,LS(p));
        if(r>m)  update(l,r,c,m+1,t,RS(p));

        d[p] = d[LS(p)] + d[RS(p)];
}

int main()
{
        int n , q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
                scanf("%lld",&a[i]);
        build(1,n,1);
        while(q--)
        {
                char C;
                int c;
                int x,y;
                scanf(" %c %d%d",&C,&x,&y);
                if(C=='C'){
                        scanf("%d",&c);
                        update(x,y,c,1LL,n,1LL);
                }
                if(C=='Q')
                        cout<<getsum(x,y,1LL,n,1LL)<<endl;
        }
        return 0;
}
