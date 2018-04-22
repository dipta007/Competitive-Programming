#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    int len = st.size();

    int up = 0;
    for(int i=0; i<len; i++)
    {
        if(isupper(st[i]) == 1) up++;
    }
    int low = len - up;

    if(up > low)
    {
        for(int i=0; i<len; i++)
        {
            st[i] = toupper(st[i]);
        }
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            st[i] = tolower(st[i]);
        }
    }
    cout << st << endl;
}
