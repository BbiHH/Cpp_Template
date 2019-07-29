#include<bits/stdc++.h>
using namespace std;
 
int i,n;
long long a,s,b[500005],ans;
 
int main()
{
    cin>>n;
    for (i=0;i<n;i++)
    {
		cin>>a;
		s+=a;
		b[i]=s;
	}
	a=0;
    for (i=0;i<n;i++)
	{
        if (i>0&&i<n-1&&b[i]*3==b[n-1]*2)
		{
			ans+=a;
		}
		if (b[i]*3==b[n-1])
		{
			a++;
		}
    }
    cout<<ans<<endl;
}

