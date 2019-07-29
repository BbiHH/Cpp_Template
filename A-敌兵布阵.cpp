#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

#define LS(a) a<<1
#define RS(a) a<<1|1
typedef long long int ll ;

int a[MAXN];
int d[4*MAXN];
int b[4*MAXN]={0};

void build(int s,int t,int p)
{
        if(s==t){
                d[p] = a[s];
                return ;
        }
        int m = (s+t)>>1;
        build(s,m,LS(p)), build(m+1,t,RS(p));
        d[p] = d[LS(p)]+d[RS(p)];
}

int getsum(int l,int r,int s,int t,int p)
{
        if(l<=s&&t<=r)
                return d[p];
        int sum = 0;
        int m = (s+t)>>1;
        if(b[p]){
                  d[p*2]+=b[p]*(m-s+1) , d[p*2+1]+=b[p]*(t-m);//更新值
                  b[p*2]+=b[p] , b[p*2+1]+=b[p];//标记下传
                  b[p] = 0;//清空标记
         }

        if(l<=m) sum+=getsum(l,r,s,m,LS(p));
        if(r>m)  sum+=getsum(l,r,m+1,t,RS(p));

        return sum ;
}

void update(int l,int r,int c,int s,int t,int p)
{
        if(l<=s&&t<=r){
                d[p]+=c*(t-s+1), b[p]+=c;
                return ;
        }
        int m = (s+t)>>1;
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
	int T;
	char s[8];
	int x,y;
	scanf("%d",&T);
	for(int o=1;o<=T;o++)
	{
		memset(b,0,sizeof(b));
		int N ;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
		cout<<"Case "<<o<<":"<<endl;
		build(1,N,1);
		int M = 40000;
		while(M--){
			scanf("%s",s);
			if(s[0]=='E') break;
			if(s[0]=='A'){
				scanf("%d%d",&x,&y);
				update(x,x,y,1,N,1);
			}
			else if(s[0]=='S'){
				scanf("%d%d",&x,&y);
				update(x,x,-y,1,N,1);
			}
			else if(s[0]=='Q'){
				scanf("%d%d",&x,&y);
				cout<<getsum(x,y,1,N,1)<<endl;
			}
		}
	}
	return 0;
}
