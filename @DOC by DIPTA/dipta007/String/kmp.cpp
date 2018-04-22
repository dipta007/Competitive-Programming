/**
Procedure:
    1. Call KMPSearch( Pattern, Text )
**/

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;

    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if( len != 0 )
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    /// LPS array print
    cout << "LPS array" << endl;
    for(int i=0; i<M; i++)
    {
        cout << pat[i] << " " << lps[i] << endl;
    }
}

void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;

    computeLPSArray(pat, M, lps);

    int i = 0;
    while(i < N)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }
        else if(pat[j] != txt[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    free(lps);
}

