#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        int a[N];
        for(int i=0;i<N;i++)
            cin >> a[i];
        int cnt=0;
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<N-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    cnt++;
                }
            }
        }
        cout << "Minimum exchange operations : "<<cnt << endl;
    }
}
