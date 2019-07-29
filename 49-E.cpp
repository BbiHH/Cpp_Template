#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long int a[100000]={0};

int main()
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		std::cin>>a[i];
	}
	sort(a,a+n);
	int add=0, det=0;
	for(int i=0;i+1<n;i++)
	{
		if(a[i]!=a[i+1])
			add++;
	}
	add++;
	if((add/2)*2==add)
		std::cout<<"First";
	else
		std::cout<<"Second";
	return 0;
}

