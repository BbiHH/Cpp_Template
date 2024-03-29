#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e4+7;

vector<int> v[MAXN];
vector<int> w[MAXN];

int fa[MAXN][31],cost[MAXN][31],dep[MAXN];
int n,m;
int a ,b ,c;

void dfs(int root,int fno){
	fa[root][0] = fno;
	dep[root] = dep[fa[root][0]]+1;
	for(int i=1;i<31;++i){
		fa[root][i] = fa[fa[root][i-1]][i-1];
	        cost[root][i] = cost[fa[root][i-1]][i-1] + cost[root][i-1];
	}
	int sz = v[root].size();
	for(int i=0;i<sz;++i){
		if(v[root][i] == fno) continue ;
		cost[v[root][i]][0] = w[root][i];
		dfs(v[root][i],root);
	}
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int tmp = dep[y] -dep[x], ans = 0;
	for(int j=0;tmp;++j,tmp >>= 1)
		if(tmp&1) ans+=cost[y][j], y = fa[y][j];
	if(y==x) return ans;
	for(int j=30;j>=0&& y!=x;--j){
		if(fa[x][j]!=f[y][j]){
			ans+=cost[x][j]+cost[y][j];
			x = fa[x][j];
			y = fa[y][j];
		}
	}
	ans += cost[x][0] +cost[y][0];
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		++a,++b;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	dfs(1,0);
	scanf("%d %d",&a,&b);
	++a,++b;
	printf("%d\n",lca(a,b));
	return 0;
}


