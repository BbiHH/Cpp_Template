#include<bits/stdc++.h>

using namespace std;

#define LS(a) (a << 1)

#define RS(a) (a << 1 | 1)

const MAXN = 1e5+7;

int a[MAXN];   //得到初始数组
int d[4*MAXN]; //线段树
int b[4*MAXN]={0}; //懒惰标记

/*建立线段树*/
// 区间 s ~ t ,  结点数 p 
void build(int s,int t,int p)
{
	if(s==t){
		d[p] = a[s];
		return ;
	}

	int m = (s+t)/2;
	//递归左右区间建树
	build(s,m,2*p),build(m+1,t,2*p+1);

	d[p] = d[2*p]+d[2*p+1];
}

/*区间查询(求和)*/
// [l~r]为查询区间,[s~t]为当前节点包含区间,p为当前节点编号
int getsum(int l,int r,int s,int t,int p)
{
	int sum = 0;
	//当前区间包含在查询区间内则返回该区间的和
	if( l<=s && t<=r )
		return d[p];

	int m = (s+t)/2;

	//左儿子与查询区间有交集,递归查询左儿子
	if(l<=m) sum+=getsum(l,r,s,m,p*2);
	//右儿子与查询区间头交集,递归查询右儿子
	if(r> m) sum+=getsum(l,r,m+1,t,p*2+1);

       return sum ;
}       

/*
 *
 */

/*区间修改(区间加上某值)*/
//[l,r]为修改区间,c为被修改元素的变化量,[s,t]为当前节点的区间,p为节点编号
void update_add(int l,int r,int c,int s,int t,int p)
{
	//当前区间为修改区间的子集直接修改区间节点的值,打上标记,结束修改
	if( l<=s && t<=r){
		d[p]+=(t-s+1)*c , b[p]+=c;
		return ;
	}
	int m = (s+t)/2;
	//如果当前节点懒惰标记非空,则更新当前节点的两个子节点的值和懒惰标记
	if(b[p] && s!=t){
		d[p*2]+=b[p]*(m-s+1) , d[p*2+1]+=b[p]*(t-m);//更新值
		b[p*2]+=b[p] , b[p*2+1]+=b[p];//标记下传
		b[p] = 0;//清空标记
	}
	if(l<=m) update(l,r,c,s,m,p*2);
	if(r> m) update(l,r,c,m+1,t,p*2+1);

	d[p] = d[p*2]+d[p*2+1];
}

/*区间查询(求和)*/
// [l~r]为查询区间,[s~t]为当前节点包含区间,p为当前节点编号
int getsum_add(int l,int r,int s,int t,int p)
{
	int sum = 0;
	//当前区间包含在查询区间内则返回该区间的和
	if( l<=s && t<=r )
		return d[p];

	int m = (s+t)/2;

	//如果当前区间懒惰标记非空,更新当前节点两个子节点的值和懒惰标记
	if(b[p]){
		d[p*2]+=b[p]*(m-s+1) , d[p*2+1]+=b[p]*(t-m);
		b[p*2]+=b[p] , b[p*2+1] +=b[p];//标记下传
		b[p] = 0 ;//清空标记
	}

	//左儿子与查询区间有交集,递归查询左儿子
	if(l<=m) sum+=getsum_add(l,r,s,m,p*2);
	//右儿子与查询区间头交集,递归查询右儿子
	if(r> m) sum+=getsum_add(l,r,m+1,t,p*2+1);

       return sum ;
}

/*
 *
 */

/*区间修改(区间修改某值)*/
//[l,r]为修改区间,c为被修改元素的值,[s,t]为当前节点的区间,p为节点编号
void update_exc(int l,int r,int c,int s,int t,int p)
{
	//当前区间为修改区间的子集直接修改区间节点的值,打上标记,结束修改
	if( l<=s && t<=r){
		d[p]=(t-s+1)*c , b[p]=c;
		return ;
	}
	int m = (s+t)>>1;
	//如果当前节点懒惰标记非空,则更新当前节点的两个子节点的值和懒惰标记
	if(b[p] && s!=t){
		d[p*2]=b[p]*(m-s+1) , d[p*2+1]=b[p]*(t-m);//更新值
		b[p*2]=b[p] , b[p*2+1]=b[p];//标记下传
		b[p] = 0;//清空标记
	}
	if(l<=m) update(l,r,c,s,m,p*2);
	if(r> m) update(l,r,c,m+1,t,p*2+1);

	d[p] = d[p*2]+d[p*2+1];
}


/*区间查询(求和)*/
// [l~r]为查询区间,[s~t]为当前节点包含区间,p为当前节点编号
int getsum_exc(int l,int r,int s,int t,int p)
{
	int sum = 0;
	//当前区间包含在查询区间内则返回该区间的和
	if( l<=s && t<=r )
		return d[p];

	int m = (s+t)/2;

	//如果当前区间懒惰标记非空,更新当前节点两个子节点的值和懒惰标记
	if(b[p]){
		d[p*2]=b[p]*(m-s+1) , d[p*2+1]=b[p]*(t-m);
		b[p*2]=b[p] , b[p*2+1]=b[p];//标记下传
		b[p] = 0 ;//清空标记
	}

	//左儿子与查询区间有交集,递归查询左儿子
	if(l<=m) sum+=getsum(l,r,s,m,p*2);
	//右儿子与查询区间头交集,递归查询右儿子
	if(r> m) sum+=getsum(l,r,m+1,t,p*2+1);

       return sum ;
}       
