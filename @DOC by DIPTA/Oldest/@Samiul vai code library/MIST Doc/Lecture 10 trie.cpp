#define SIZE 1010

struct node {
    int val;
    int child[26];

    void clear() {
        memset(child, 0, sizeof child );
    }
}trie[SIZE];

int ind;

void clearTrie() {
    trie[0].clear();
    ind = 1;
}

void insertTrie ( string s ) {
    int len = s.length();

    int cur = 0;

    for ( int i = 0; i < len; i++ ) {
        int c = s[i] - 'a';

        if ( trie[cur].child[c] == 0 ) {
            trie[ind].clear();
            trie[cur].child[c] = ind;
            ind++;
        }
        cur = trie[cur].child[c];
    }

    ///You can mark cur as an ending node, if needed
}
