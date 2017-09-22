#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAX = 1e5+4;

int a[MAX];
int cnt[MAX];
int fst[MAX];
int scnd[MAX];
int ans[MAX];
int dfrnc[MAX];

int main()
{
    int n;
    cin >> n;
    /// cnt array te 0 set korsi
    /// cnt array die 1 ta value koto ber array te ase ta ber kortesi
    /// cnt[ 4 ] = 2 mane 4 array te 2 ber ase
    memset(cnt, 0, sizeof(cnt));

    /// ans array te ans ase naki na ta set korsi
    /// ans[ 4 ] = 1 means ans er modhe 4 ase
    memset(ans, 0, sizeof(ans));

    /// loop ghurai input nisi
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt [ a[i] ]++; /// cnt array te increment kortesi

        if(cnt [ a [i] ] == 1) /// 1st position of a[i]
        {
            fst[ a[i] ] = i;
        }
        if(cnt [ a [i] ] == 2) /// 2nd position of a[i]
        {
            scnd[ a[i] ] = i;
        }
    }

    /// distinct element gula ber korsi
    /// cnt[ 3] = 1 mane 3 1 ber i ase
    /// 3 distinct
    for(int i=1; i<=1e5; i++)
    {
        if(cnt[i] == 1)
        {
            ans[i] = 1;
            dfrnc[i] = 0;
        }
    }

    /// jesob element minimum 2 ber ase
    /// oi gula k ei loop die ber korsi
    for(int i=1; i<=1e5; i++)
    {
        if(cnt[i] > 1) /// mane 2 ber or er besi ase
        {
            int ff = fst[i]; /// fst position pailam
            int ss = scnd[i]; /// scnd pos pailam
            int diff = ss - ff; /// scnd pos theke fst pos minus kore difference pailam

            int flg = 1; /// eta ans hoite pare cinta kore nilam


            /// ei loop koto ber cholbe? - cnt[i] ber ghuraisi k = 1 theke cnt[i]
            /// j die diff poriman pos por por jump korsi
            for(int j=ff,k=1; k<=cnt[i] ;k++, j+=diff)
            {
                if(a[j] != i)
                {
                    flg = 0; /// i ans na
                    break;
                }
            }

            if(flg == 1) /// prove korla, je i ans e ase
            {
                ans[i] = 1;
                dfrnc[i] = diff;
            }
        }
    }

    int count = 0;
    for(int i=1; i<=1e5; i++)
    {
        if(ans[i]==1) count++;
    }

    cout << count << endl;
    for(int i=1; i<=1e5; i++)
    {
        if(ans[i]==1)
            cout << i << " " << dfrnc[i] << endl;
    }
}
