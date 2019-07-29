#include<iostream>

using namespace std;

//    给定范围  a  ---  b 
//    (b-a)/10+x   x为判断
//    b-a 
//    (n - n%x)*10 / x == 2  i++
//

int x[5]={1,10,100,1000,10000};

int main()
{
        int L,R;
        cin>>L>>R;
        int sum = 0;
        for(int i=L;i<=R;i++)
        {
                int res = i;
                while(res>=1)
                {
                    int o=0;
                     for(int j=4;j>=0;j--)
                     {
                         if(res/x[j]>0)
                         {
                             o = j;
                                if(res/x[j]==2)
                                    sum++;
                             break;
                          }
                      }
                    res = res%x[o];
                }
        }
        cout<<sum;
        return 0;
}
