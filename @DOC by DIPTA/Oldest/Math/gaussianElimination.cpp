#define MAXROW 512
#define MAXCOL 512

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

int gauss(int n, int m, double ar[MAXROW][MAXCOL], vector<double>& res){
    res.assign(m, 0);
    vector <int> pos(m, -1);
    int i, j, k, l, p, free_var = 0;

    for (j = 0, i = 0; j < m && i < n; j++){
        for (k = i, p = i; k < n; k++){
            if (abs(ar[k][j]) > abs(ar[p][j])) p = k;
        }

        if (abs(ar[p][j]) > EPS){
            pos[j] = i;
            for (l = j; l <= m; l++) swap(ar[p][l], ar[i][l]);

            for (k = 0; k < n; k++){
                if (k != i){
                    double x = ar[k][j] / ar[i][j];
                    for (l = j; l <= m; l++) ar[k][l] -= (ar[i][l] * x);
                }
            }
            i++;
        }
    }

    for (i = 0; i < m; i++){
        if (pos[i] == -1) free_var++;
        else res[i] = ar[pos[i]][m] / ar[pos[i]][i];
    }

    for (i = 0; i < n; i++) {
        double val = 0.0;
        for (j = 0; j < m; j++) val += (res[j] * ar[i][j]);
        if (abs(val - ar[i][m]) > EPS) return -1;
    }

    return free_var;
}

int n, m;
double ar[MAXROW][MAXCOL];

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

