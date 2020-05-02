/**
Procedure:
    1. Set value in array a[MX][MX]
    2. Call get(row,col) to get value
Time Complexity = O(col * col * row)
Space Complexity = O(row)
**** MUST HAVE AT LEAST ONE POSITIVE NUMBER
**/
struct kadane
{
    int u,d,sum;
    kadane()
    {
        u=-1,d=-1,sum=0;
    }
};
struct kadane2d
{
    int a[MX][MX];
    int get(int r, int c)
    {
        int maxSum=-INF,maxL,maxR,maxU,maxD;
        int kad[r];
        for(int left=0; left<c; left++)
        {
            CLR(kad);
            for(int right=left; right<c; right++)
            {
                for(int i=0; i<r; i++)
                {
                    kad[i]=kad[i]+a[i][right];
                }
                kadane curr,maxy;
                //This FOR for 1D-Kadane Algorithm
                for(int i=0; i<r; i++)
                {
                    if(curr.sum<0)
                    {
                        curr.sum = kad[i];
                        curr.u=i;
                        curr.d=i;
                    }
                    else
                    {
                        curr.sum = curr.sum + kad[i];
                        curr.d=i;
                    }
                    if(curr.sum > maxy.sum)
                    {
                        maxy=curr;
                    }
                }
                if(maxy.sum>maxSum)
                {
                    maxSum=maxy.sum;
                    maxL=left;
                    maxR=right;
                    maxU=maxy.u;
                    maxD=maxy.d;
                }

            }
        }
    }
};
