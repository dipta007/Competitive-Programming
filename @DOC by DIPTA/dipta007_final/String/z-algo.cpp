const int MAX = 1e5 + 4;
int Z[MAX];
void zAlgo(string &st)
{
    int n = st.size();

    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && st[R-L] == st[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            /// We are operating in the box
            int k = i-L;
            /// Does not touch the right of the box
            if (i + Z[k] < R+1)
                Z[i] = Z[k];
            /// Touched the right of the box, so calculate again
            else
            {
                L = i;
                while (R < n && st[R-L] == st[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
