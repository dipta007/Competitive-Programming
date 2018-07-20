/// Prufer code is a sequence of numbers that represents a unique tree
/// Tree with n vertices will have prufer code of length n-2

void pruferCodeToTree(vi &prufer) {

    /*Stores number count of nodes in the prufer code*/
    map<int,int> mp;

    /* Set of integer absent in prufer code*/
    set<int> st;

    int len = prufer.size();
    int n = len + 2;

    /*Count frequency of nodes*/
    for ( int i = 0; i < len; i++ ) {
        int t = prufer[i];
        mp[t]++;
    }

    /*Find the absent nodes*/
    for ( int i = 1; i <= n; i++ ) {
        if ( mp.find ( i ) == mp.end() ) st.insert ( i );
    }

    /*Connect Edges*/
    for ( int i = 0; i < len; i++ ){
        int a = prufer[i]; // First node

        /*Find the smallest number which is not present in prufer code now*/
        int b = *st.begin(); // Second node

        printf ( "%d %d\n", a, b ); // Edge of the tree

        st.erase ( b ); // Remove absent list
        mp[a]--; // Remove from prufer code
        if ( mp[a] == 0 ) st.insert ( a ); // If a becomes absent
    }

    /*The final edge*/
    printf ( "%d %d\n", *st.begin(), *st.rbegin() );
}

/// Applications
/// 1. Given an array of degrees of a tree. Find the number of labeled trees possible
// A node with degree d will occur in prufer code d-1 times
// and there is total of n-2 slots
// So using combination we can find the total number of trees
// For [d1, d2], Ans = C(n-2, d1) + C(n-2-d1, d2)

/// 2. Creation of random tree
// For getting a tree of n nodes
// Generate prufer code of n-2 slots
// And call the above function to get the tree

/// If the number of vertices = n
/// Then total number of trees possible = n ^ (n-2)

/// complete bipartite graph
/// a complete bipartite graph K(m,n) has m^(n-1) * n^(m-1) spanning trees.
