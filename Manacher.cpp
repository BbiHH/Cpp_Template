#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int p[N],mx,id,cnt=0;

char s[N],t[N];

void Pre()
{
	s[++cnt]='$';
	s[++cnt]='#';
	for(int i=0;i<strlen(t);i++)
	{
		s[++cnt]=t[i];
		s[++cnt]='#';
	}
	s[++cnt]='\0';
}


void manacher()
{
	mx = -1;
	id = 0;
	for(int i=0;i<cnt;i++)
	{
		if(i<=mx) p[i]=min(p[id*2-1],mx-i);
		else p[i] = 1;
		while(s[i-p[i]]==s[i+p[i]]) p[i]++;
		if(mx<i+p[i]) id = i,mx = i+p[i];
	}
}

int main()
{
	int ans = 0;
	cin>>t;
	Pre();
	manacher();
	for(int i=0;i<cnt;i++)
		ans = max(ans,p[i]-1);
	cout<<ans<<endl;
}
