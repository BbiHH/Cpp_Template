#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool flag = false;

long long int ans;
int n;

void DFS(int x, long long y)
{
       	if(x >19 || flag ==1){	return; }

       	if(y%n == 0) { flag = 1; printf("%lld\n",y); return ; } 
	DFS(x+1, y*10);
       	DFS(x+1, y*10+1);
}


int main()
{
    while(cin>>n)
    {
	    if(n==0)
		    break;
	    flag = false;
	    DFS(1,1);
    }
}
