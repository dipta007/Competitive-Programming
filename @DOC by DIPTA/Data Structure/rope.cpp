#include <bits/stdc++.h>
using namespace std;
#include <ext/rope> //header with rope
using namespace __gnu_cxx;

crope l[50005],tmp,kk;
char st[205];

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    //ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        int vv=1;
        int cntC = 0;
        FOR(i,1,n)
        {
            int tt;
            getI(tt);
            if(tt==1)
            {
                int pos;
                scanf("%d%s",&pos,st);
                pos -= cntC;
                tmp.insert(pos, st);
                l[vv++] = tmp;
            }
            else if(tt==2)
            {
                int pos,rmv;
                getII(pos,rmv);
                pos -= cntC;
                rmv -= cntC;

                tmp.erase(pos-1, rmv);
                l[vv++] = tmp;
            }
            else
            {
                int v,pos,c;
                getIII(v,pos,c);
                v-=cntC;
                pos-=cntC;
                c-=cntC;
                kk = l[v].substr(pos-1,c);
                cntC += count(kk.begin(), kk.end(), 'c');
                cout << kk << endl;

            }
        }
    }

    return 0;
}
