#include<iostream>

using namespace std;

template<class T>
T abs(T x1,T x2)
{
	return max(x1,x2);
}

int main()
{
	int a=2,b=3;
	double c = 3.7,d=1.2;
	cout<<abs(a,b)<<abs(c,d);
}
