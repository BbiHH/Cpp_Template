#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int w[3][MAXN]={0};
int d[MAXN]={0};
	int n ;

void init()
{
	int index;
	if(w[1][1]>w[2][1]){
		d[1]=w[1][1];
		index=1;
	}
	else{
		d[1]=w[2][1];
		index=2;
	}
	for(int i=2;i<=n;i++){
		if(d[i-1]+w[(index)%2+1][i]>=d[i-2]+w[(index+1)%2+1][i])
		{
			d[i]=d[i-1]+w[index%2+1][i];
			index++;
		}
		else
			d[i]=d[i-2]+w[(index+1)%2+1][i];
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<3;i++)
	for(int j=1;j<=n;j++)
		cin>>w[i][j];
	init();
	cout<<d[n]<<endl;
}
	


