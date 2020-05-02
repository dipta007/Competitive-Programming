/**
    We can improve performance by using bottom up dynamic programming using
    tabulation instead of using recursion. Below is bottom up dynamic programming solution to problem.
**/

public class CoinChange
{
    static int numOfWays(int [] coins, int amount)
    {
        int [][] ways = new int[coins.length][amount+1];
        for (int i = 0; i < coins.length; i++)
        {
            ways[i][0] = 1;
        }
        for (int i = 1; i <= amount; i++)
        {
            ways[0][i] = 0;
        }
        int j = 0;
        for (int i = 1; i < coins.length; i++)
        {
            for (j = 1; j < coins[i]; j++)
            {
                ways[i][j] = ways[i-1][j];
            }
            for (; j <= amount; j++)
            {
                ways[i][j] = ways[i-1][j] + ways[i][j - coins[i]];
            }
        }
        return ways[coins.length-1][amount];
    }

    public static void main(String[] args)
    {
        System.out.println("Number of ways:"+numOfWays(new int[] {0,1,5,10},5371));
    }
}
//
//In above solution we are storing number of ways for each coin in 2-D array.
//We can optimize to use only 1-D array since every time loop runs 1-D array contain number of ways till previous coin.
//Memory optimize version of above solutions is:

static int numOfWays1(int [] coins, int amount)
{
    int [] ways = new int[amount+1];
    ways[0] = 1;
    for (int i = 0; i < coins.length; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            ways[j]+=ways[j-coins[i]];
        }
    }
    return ways[amount];
}

