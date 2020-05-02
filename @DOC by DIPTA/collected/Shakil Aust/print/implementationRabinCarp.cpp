using namespace std;

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX 1000010
typedef unsigned long long ull;

char t[MAX], s[MAX];

void patHash (ull sLen, ull h_s[], ull p_pow[]) {
    h_s[0] = 0ULL;
    for (size_t i = 0; i < sLen; ++i)
        h_s[0] += (s[i] - 'a' + 1) * p_pow [i];

    for (size_t i = 1; i < sLen; ++i)
        h_s[i] = (h_s[i - 1] * p_pow[1]) - (s[sLen - i] - 'a' + 1) * p_pow [sLen] + (s[sLen - i] - 'a' + 1);

    sort (h_s, h_s + sLen);
}

bool subStr (ull cur_h, size_t sLen, ull h_s[]) {
    int low = 0;
    int high = sLen - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) >> 1;
        if (cur_h == h_s[mid]) return true;
        if (cur_h > h_s[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int rabinKarp (size_t tLen, ull p_pow[]) {
    size_t sLen = strlen(s);
    ull *h_s = new ull [sLen];
    ull cur_h = 0ULL;
    if (sLen > tLen) return 0;
    patHash(sLen, h_s, p_pow);

    for (int i = tLen - sLen, j = 0; i < tLen; ++i, ++j) cur_h += ((t[i] - 'a' + 1) * p_pow [j]);
    // Loop through all the strings of length |S| in T and compare them
    int count = 0;
    for (int i = tLen - sLen, j = 0; i >= 0; --i, ++j) {
        if (i != (tLen - sLen)) {
            cur_h -= ((t[tLen - j] - 'a' + 1) * p_pow[sLen - 1]);
            cur_h *= p_pow[1];
            cur_h += (t[i] - 'a' + 1);
        }
        // Give the hashes to the same degree and compare
        if (subStr(cur_h, sLen, h_s)) ++count;
    }

    return count;
}

void setT (size_t tLen, ull p_pow[]) {
    const int p = 31;
    // All powers of p
    p_pow [0] = 1;
    for (size_t i = 1; i < tLen; ++i) p_pow [i] = p_pow [i - 1] * p;
}

int main () {
    ull n;
    // freopen("input.txt", "r", stdin);
    cin >> t;
    cin >> n;
    size_t tLen = strlen (t);
    ull *p_pow = new ull [tLen];
    setT (tLen, p_pow);

    while (n--) {
        cin >> s;
        cout << rabinKarp (tLen, p_pow) << endl;
    }
    return 0;
}
