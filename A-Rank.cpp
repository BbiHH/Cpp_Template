#include<bits/stdc++.h>

using namespace std;

struct Stu
{
	long long int ID;
	int socre;
};

bool func1(Stu &s1,Stu &s2)
{
	return s1.socre>=s2.socre;
}

int main()
{
	long long int  i ;
	cin>>i;
	vector<Stu>B;
	Stu s;
	int ss;
	while(1)
	{
		cin>>s.ID>>s.socre;
		if(s.ID==0LL&&s.socre==0)
			break;
		if(s.ID==i)
			ss = s.socre;
		B.push_back(s);
	}
	sort(B.begin(),B.end(),func1);
	int rank = 1;
	auto p = B.begin();
	for(p;p!=B.end();p++)
	{
		if(p->socre>ss)
			rank++;
		else
			break;
	}
	cout<<rank<<endl;
	return 0;
}
