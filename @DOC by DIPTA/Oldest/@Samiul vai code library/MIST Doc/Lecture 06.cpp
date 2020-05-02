
/// 0/1 Knapsack

int w[1010], p[1010];

int n;

int memo[1010][210];

int dp ( int pos, int cap ) {
    if ( pos >= n ) {
        return 0;
    }

    if ( memo[pos][cap] != -1 ) return memo[pos][cap];b


    int profit = 0;

    int option1 = 0 + dp ( pos + 1, cap );

    int option2 = 0;
    if ( w[pos] <= cap ) option2 = p[pos] + dp ( pos + 1, cap - w[pos] );

    profit = max (option1,option2);

    return memo[pos][cap] = profit;
}


int main () {
    memset ( memo,-1,sizeof memo);
}



/*****************apple tree

*/

int arr[100000], n, t;

int apple[5][100000];

int dp_apple(int tree, int s)
{
    int res=0;


   if(s>n)
        return 0;
   if(apple[tree][s]!=-1)return apple[tree][s];

    if(arr[s]==tree)
        res++;
    int op1=dp_apple(tree, s+1);
    int op2=dp_apple(tree+1, s+t);

    apple[tree][s]=res+max(op1, op2);
    return res+max(op1, op2);

}
