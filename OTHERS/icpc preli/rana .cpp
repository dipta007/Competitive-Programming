#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,arr[12]={31,28,31,30,31,30,31,31,30,31,30,31},p1,q1,p2,q2,flag=1;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>p1>>q1>>p2>>q2;
        if(p1==q1==p2==q2) flag=3;
        else if(p1>12 && q1>12 || p2>12 && q2>12) flag=3;
        else if(p1>p2 && q1>q2) flag=3;
        else if(p1>12 || p2 >12)
            if(q1>12 || q2>12) flag=3;
        else if(p1<=12 && p2<=12 && q1<=12 && q2<=12) flag=2;
        else
        {
            int m1,d1;
            d1=(p1<12) ? p1,m1=q1:q1,m1=p1;
            int m2,d2;
            d2=(p2<12) ? p2,m2=q2:q2,m2=p2;
            if(d1>arr[m1-1] || d2>arr[m2-1]) flag=3;

        }


        if(flag==3) cout<<"Case "<<i<<": "<<"I am sure there is some kinda mistake!"<<endl;
        else if(flag==2) cout<<"Case "<<i<<": "<<"Oh no it is ambiguous!"<<endl;
        else cout<<"Case "<<i<<": "<<"Okay got it!"<<endl;

    }
    return 0;
}
