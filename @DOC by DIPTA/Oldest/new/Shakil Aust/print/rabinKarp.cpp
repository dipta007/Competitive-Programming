using namespace std;

#include <iostream>
#include <algorithm>
#include <cstring>

typedef unsigned long long ull;

void Rabin_Karp (char t[], char s[]) {
    const int p = 31;
    size_t t_len = strlen(t);
    size_t s_len = strlen(s);
    size_t p_len = max (t_len, s_len);
    ull *p_pow = new ull [p_len];
    ull *h = new ull [t_len];

    // All powers of p
    p_pow [0] = 1;
    for (size_t i = 1; i < p_len; ++i) p_pow [i] = p_pow [i - 1] * p;

    // Find the hashes of all prefix of T
    for (size_t i = 0; i < t_len; ++i) {
        h[i] = (t[i] - 'a' + 1) * p_pow [i];
        if (i) h[i] += h[i - 1];
    }

    // Find hash of S
    ull h_s = 0ull;
    for (size_t i = 0; i < s_len; ++i)
        h_s += (s[i] - 'a' + 1) * p_pow [i];

    // Loop through all the strings of length |S| in T and compare them
    for (size_t i = 0; i + s_len - 1 < t_len; ++i) {
        ull cur_h = h [i + s_len - 1];
        if (i) cur_h -= h[i - 1];
        // Give the hashes to the same degree and compare
        if (cur_h == h_s * p_pow [i])
            cout << i << endl;
    }
}

int main () {
    char t[100], s[100];
    cin >> t >> s;

    Rabin_Karp (t, s);
    return 0;
}
