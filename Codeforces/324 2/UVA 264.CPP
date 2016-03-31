#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int x=1,y=0;
        for(int i=1; ;i++)
        {
            x=x+i;
            if(x>n)
            {
                x=x-i;
                y=i;
                break;
            }
        }

        cout<<x<<" "<<y<<endl;

        int you = n-x;

        int a=you+1;
        int b = y +you;


        cout<<a<<" / "<<b<<endl;





    }
}
