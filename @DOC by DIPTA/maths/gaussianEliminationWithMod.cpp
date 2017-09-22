
/***

Gauss-Jordan Elimination

n = number of linear equations
m = number of variables
ar[i][m] = right-hand side value of constants

For instance, the system of linear equations becomes:

2x + y -z = 8      ----->  (i)
-3x -y + 2z = -11  ----->  (ii)
-2x + y + 2z = -3  ----->  (iii)

n = 3 (x, y, z), m = 3 (i, ii, iii)
ar[0] = {2, 1, -1, 8}    ----->  (i)
ar[1] = {-3, -1, 2, -11} ----->  (ii)
ar[2] = {-2, 1, 2, -3}   ----->  (iii)

Returns -1 when there is no solution
Otherwise returns the number of free variables (0 for an unique solution)
Contains a solution in the vector res on successful completion
Note that the array is modified in the process

***/

#define MAXROW 512
#define MAXCOL 512

pii extendedEuclid(ll a, ll b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(ll a, ll modd) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, modd);
  return ((ret.ff % modd) + modd) % modd;
}

ll MOD(ll x, ll modd)
{
    return (x%modd+modd)%modd;
}


int gauss(int n, int m, ll ar[MAXROW][MAXCOL], ll modd, vector<ll>& res){
    res.assign(m, 0);
    vector <ll> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (labs(ar[k][j]) > labs(ar[p][j])) p = k;
        }

        if (labs(ar[p][j]) > 0){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);

            for (k = 0; k < n; k++){
                if (k != i){
                    ll upor = ar[k][j];
                    ll nich = ar[i][j];
                    nich = modularInverse(nich, modd);
                    ll x = ((ll)upor * nich)%modd;
                    for (l = j; l <= m; l++) ar[k][l] = MOD(ar[k][l] - ((ll)ar[i][l] * x)%modd , modd);
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1)
        {
            //cout << " free " << i << endl;

            free_var++;
        }
        else
        {
            ll upor = ar[pos[i]][m];
            ll nich = ar[pos[i]][i];
            nich = modularInverse(nich, modd);
            ll x = ((ll)upor * nich)%modd;
            res[i] = x;
        }
    }

    for (i = 0; i < n; i++) {
        ll val = 0;
        for (j = 0; j < m; j++) val = (val + ((ll)res[j] * ar[i][j])%modd )%modd;
        if (labs(val - ar[i][m]) > 0) return -1;
    }

    return free_var;
}

int n, m;
ll ar[MAXROW][MAXCOL];

int main(){
    vector <double> res;
    int free_variables;

    /// Example from wikipedia
    n = 3; /// 3 Equations
    m = 3; /// 3 Variables
    ar[0][0] = 2, ar[0][1] = 1, ar[0][2] = -1, ar[0][3] = 8; /// 2x + y -z = 8
    ar[1][0] = -3, ar[1][1] = -1, ar[1][2] = 2, ar[1][3] = -11; /// -3x -y + 2z = -11
    ar[2][0] = -2, ar[2][1] = 1, ar[2][2] = 2, ar[2][3] = -3; /// -2x + y + 2z = -3


    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables);
    printf("x = %0.2f\n", res[0]);
    printf("y = %0.2f\n", res[1]);
    printf("z = %0.2f\n", res[2]);

    /// Another example
    n = 1; /// 1 Equation
    m = 3; /// 3 Variables
    ar[0][0] = 1, ar[0][1] = 1, ar[0][2] = 1, ar[0][3] = 10; /// x + y + z = 10

    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables); /// 2 free variables (they are assigned 0)
    printf("x = %0.2f\n", res[0]);
    printf("y = %0.2f\n", res[1]);
    printf("z = %0.2f\n", res[2]);


    /// Another example when no solution exists
    n = 1; /// 1 Equation
    m = 3; /// 3 Variables
    ar[0][0] = 0, ar[0][1] = 0, ar[0][2] = 0, ar[0][3] = 10; /// 0 + 0 + 0 = 10, inconsistent

    free_variables = gauss(n, m, ar, res);
    printf("Free variables = %d\n", free_variables); /// -1 implies no valid solution exists

    return 0;
}


