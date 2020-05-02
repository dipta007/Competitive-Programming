// Returns true if any of the element in arrray all[0...num-1] is zero,, else returns false.
bool isZero (int num, int all[]) { for (int i = 0; i < num; ++i) if (!all[i]) return true; return false; }
// Returns true if more than (num - lim) elements in arrray all[0...num-1] is zero,, else returns false.
// lim :: the lowest number of distinct strings that must have to be present in the sliding window.
bool isZero (int num, int lim, int all[]) { int cnt = 0; for (int i = 0; i < num; ++i) if (!all[i] && (++cnt && cnt > num - lim)) return true; return false; }
// Returns the string number of which this suffix is a subString.
int inside (int pos, vector <int> len) { for (int i = 0; i < len.size(); ++i) if (pos < len[i]) return i; }
// Sets all lenth of the strings according to the concated string.
void setAllLen (vector <int> &len) { for (int i = 1; i < len.size(); ++i) len[i] += (len[i-1] +1); }

// N :: the length of the contated string.
// len :: the lengths of the input strings.
int slidingWindow (int N, vector <int> len) {
    int up = 0, down = 0, ans = 0;
    int num = len.size();
    int *all = new int [num];
    // This is the only way to initialize all[0...num-1] array.
    memset (all, 0, num * sizeof (int)); 
    setAllLen(len);
    
    while (down < N) {
        while (isZero(num, all) && down < N) {
            all [inside(SA[down], len)] ++;
            down++;
        }

        while(!isZero(num, all)) {
            ans = max (ans, lcp(SA[up], SA[down - 1]));
            all [inside(SA[up], len)] --;
            up++;
        }
    }
    return ans;
}