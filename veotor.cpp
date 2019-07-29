#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>

using namespace std;

double square(double x)
{
	return x*x;
}

int main()
{
	transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),square);
	cout<<endl;
	return 0;
}


