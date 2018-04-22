#include <stdio.h>
#include <utility>
#include <stack>

using namespace std;

#define mp make_pair

typedef pair<int,int> Matrix;

Matrix mat[ 26 ];
char str[ 1003 ];

int main()
{
    int n;
    char m;
    int r, c;

    scanf("%d\n",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%c %d %d\n",&m,&r,&c);
        mat[ m-'A' ] = mp( r, c );
    }

    while ( gets( str ) )
    {
        stack< Matrix > stk;
        bool ok = true;
        int ans = 0;
        for (int i=0; str[i]; i++)
        {
            Matrix B;
            if ( str[i] == '(' )
            {
                stk.push( mp(-1,-1) );
                continue;
            }
            else if ( str[i] == ')' )
            {
                B = stk.top(); stk.pop(); stk.pop();
            }
            else B = mat[ str[i]-'A' ];
            if ( !stk.empty() && stk.top()!=mp(-1,-1) )
            {
                Matrix A = stk.top(); stk.pop();
                if ( A.second != B.first )
                {
                    ok = false;
                    break;
                }
                ans += A.first * A.second * B.second;
                B = mp( A.first, B.second );
            }
            stk.push( B );
        }
        if ( ok ) printf("%d\n",ans);
        else puts("error");
    }

    return 0;
}
