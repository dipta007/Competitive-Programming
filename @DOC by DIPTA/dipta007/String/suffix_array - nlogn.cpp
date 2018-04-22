#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 600004;
string text;
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l)
{
    return (y [a] == y [b] && y [a + l] == y [b + l]);
}

void Sort ()
{
    for (int i = 0; i < m; ++i)
        w [i] = 0;
    for (int i = 0; i < N; ++i)
        ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i)
        w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i)
        SA [--w [x [y [i]]]] = y [i];
}

void DA ()
{
    ++N;
    for (int i = 0; i < N; ++i)
        x [i] = text [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p)
    {
        for (p = 0, i = N - j; i < N; i++)
            y [p++] = i;
        for (int k = 0; k < N; ++k)
            if (SA [k] >= j)
                y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i)
            x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i)
        SA [i - 1] = SA [i];
    --N;
}

void kasaiLCP ()
{
    int i,j,k;
    for(i=0; i<N; i++) c [ SA[i] ] = i;

    k = 0;
    for (i = 0; i < N; i++) {
        if (c[i] == (N - 1)) k = 0;
        else {
            j = SA[c[i] + 1];
            while ( ((i + k) < N) && ((j + k) < N) &&
                    (text[i + k] == text[j + k]) )
                k++;
        }
        LCP[c[i]] = k;

        if(k > 0) k--;
    }
}

void suffixArray ()
{
    m = 256;
    N = text.size();
    DA ();
    kasaiLCP ();
}

int main()
{
    while( cin >> text )
    {
        text += "$";
        suffixArray();
        int n = text.size();
        for(int i=0; i<n; i++)
        {
            cout << SA[i] << " " << text.substr(SA[i]) << " " << LCP[i] << endl;
        }
    }
}

