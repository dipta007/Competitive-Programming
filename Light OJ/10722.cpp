/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.math.*;
import java.util.*;

/**
 *
 * @author Shubhashis
 */

class function
{
    Scanner sc = new Scanner(System.in);
    static int b,n;
    static boolean[][] visited= new boolean[104][4];
    static BigInteger[][] dp=new BigInteger[104][4];
    void begin()
    {
        while(sc.hasNext())
        {
            b=sc.nextInt();
            n=sc.nextInt();
            if(b==0 && n==0) break;

            for(int i=0;i<102;i++)
            {
                for(int j=0;j<3;j++)
                {
                    visited[i][j]=false;
                }
            }

            System.out.println(call(0,0));
        }
    }

    static BigInteger call(int in, int one)
    {
        if(in>=n) return BigInteger.ONE;
        if(visited[in][one]==true) return dp[in][one];

        BigInteger ansBigInteger=BigInteger.ZERO;
        int mn = Math.min(b, 4);

        for(int i=0;i<mn;i++)
        {
            if(in==0 && i==0) continue;
            if(one==1 && i==3) continue;

            if(i==1) ansBigInteger = ansBigInteger.add(call(in+1, 1));
            else ansBigInteger = ansBigInteger.add(call(in+1,0));
        }
        BigInteger four = call(in+1, 0);
        int baki=b-mn;
        BigInteger ans = BigInteger.valueOf(baki).multiply(four);
        ansBigInteger = ansBigInteger.add(ans);

        visited[in][one]=true;
        return dp[in][one]=ansBigInteger;
    }
}
public class Main {

    public Main() {
    }
    public static void main(String[] args) {
        function my=new function();
        my.begin();
    }

}

