#include <bits/stdc++.h>

using namespace std;

#define LS(a) a<<1
#define RS(a) a<<1|1

const int MAXN = 2e5+7;

int a[MAXN];
int d[MAXN*4];

void build(int s,int t,int p)
{
        if(s==t){
                d[p]=a[s];
                return ;
        }
        int m = (s+t)>>1;
        build(s,m,LS(p)),build(m+1,t,RS(p));
        d[p] = max(d[LS(p)],d[RS(p)]);
}

void update(int l, int r, int c, int s, int t, int p) {
  if (l <= s && t <= r) {
    d[p] = c;
    return;
  }
  int m = (s + t)>>1;
  if (l <= m) update(l, r, c, s, m, LS(p));
  if (r > m) update(l, r, c, m + 1, t, RS(p));

     d[p] = max(d[LS(p)],d[RS(p)]);
}

int getmax(int l, int r, int s, int t, int p) {

  if (l <= s && t <= r)
    return d[p];
  int m = (s + t)/2 , M = 0;
  if (l <= m) M = max(M,getmax(l,r, s, m, LS(p)));
if(r > m) M = max(M,getmax(l,r, m+1, t, RS(p)));

  return M;
}

int main()
{
	int T ;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		build(1,n,1);
		int q;
		int x, y;
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<getmax(x,y,1,n,1)<<endl;
		}
	}
	return 0;
}
