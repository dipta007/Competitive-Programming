ll ca[MAX];
void catalan()
{
    ca[0]=1;
    for(ll i=1;i<=m;i++)
        ca[i]=ca[i-1]*(4*i-2)/(i+1);
}
/// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845
/*************** Applications ********************
 1. Parenthesis matching: Cn counts the number of expressions containing
    n pairs of balanced parenthesis. ex: ()(), (())
 2. Binary Parenthesis: Cn is the number of binary parenthesis of (n+1)
 3. Polygon triangulation: Cn is the number of different ways a convex
    polygon with n+2 sides can be cut into triangles bu connecting vertices
    with straight lines.
 4. Balanced binary tree: The number of full binary trees with n internal node
    is the nth catalan number
 5. Rooted Binary tree: The number of rooted binary tree with n nodes is Cn.
    Moreover, Cn is the number of rooted binary tree with height n.
 6. Rooted plane tree: Number of rooted plan tree with n+1 nodes is Cn.
 7. Non Crossing Partitions: The number of non-crossing partitions of n elemnent
    set is Cn
 8. Multiplications Orderings: Cn is the number of multiplication ordering of n+1
    numbers
 9. Skew polyominos: Number of organizing n skew polyominos is Cn
 10.Hand-shaking: If 2n people shake their hands, then the number of way to shake
    without any crossing is Cn.
 11.Diagonal-avoiding paths: in a n*n square, if you want to go from upper left
    to lower right or vice versa then there are Cn paths.
 12.Mountain ranges: How many mountain you can form but n upstroke(/) and n downstroke(\).
    The number is Cn.
 13.Dyck work: Cn is the number of Dyck words of length 2n. Dyck word is a string of n X's
    and n Y's such that no initial segment of the string has more Y than X
    wx: XXXYYY, XYXXYY, XYXYXY, XXYYXY, XXYXYY
 14.Permutation: Cn is the number of permutations tha avoid permutation pattern 123
    or any of the other patterns of length 3, the number of permutations with no
    three-term increasing. ex: for three: 132, 213, 231, 312, 321
 15.Cn is  ther number of standard young tableaux whose diagram is 2*n rectangle.
    In other words, it is the number of ways the number 1,2,....2n can be arranged
    in a 2*n rectangle so that each row and each column is increasing.
/*************************************************/

ll sca[MAX];
void superCatalan()
{
    sca[0] = sca[1] = 1;
    FOR(i,2,MAX-1)
    {
        sca[i] = (3LL * (2LL*i - 3) * sca[i-1] - (i-3) * sca[i-2]) / i;
    }
}
/// 1, 1, 3, 11, 45, 197, 903, 4279, 20793, 103049, 518859, 2646723, 13648869, 71039373
/*************** Applications ********************
 1. Expression parenthesis: The nth number is the value of different ways
    of inserting parenthesis into a sequence of n symbols, without any
    parenthesis around the whole sequence.
/*************************************************/

ll narayana(ll n, ll k)
{
    return (nCr(n, k) * nCr(n, k-1)) / n;
}

/*************** Applications ********************
 1. Parenthesis matching: N(n,k) counts the number of ways we can match n
    parenthesis such that () occurs exactly k times
 2. N(n,k) counts the number of ways we can build Dyck Paths of length 2n
    exactly k peaks.
 3. Non crossing partition: N(n,k) counts the number of ways we can partition
    n elements such that they dont cross and have exactly k parts
/*************************************************/

