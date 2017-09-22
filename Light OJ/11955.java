

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Shubhashis
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t;
        t=in.nextInt();
        String gh = in.nextLine();
        ArrayList < BigInteger> arr = new ArrayList<>();
        arr.add(BigInteger.ONE);
        for(int i=1;i<=50;i++)
        {
            arr.add(arr.get(i-1).multiply(BigInteger.valueOf(i)));
        }
        for(int ci=1;ci<=t;ci++)
        {
            String st;
            st=in.nextLine();
            data res=getFromString(st);
            System.out.print("Case "+ci+": ");
            int ak=res.power;
            int bk=0;
            int pk=0;
            String co,a,b;
            int cnt=0;
            while(true)
            {
                if(cnt==1)
                {
                    System.out.print("+");
                }
                cnt=1;

                if(pk==0 || pk==res.power) co="";
                else
                {
                    BigInteger hor=arr.get(res.power);
                    BigInteger lob=arr.get(res.power-pk).multiply(arr.get(pk));
                    co=String.valueOf(hor.divide(lob));
                    System.out.print(co+"*");
                }

                if(ak>0)
                {
                    System.out.print(res.a);
                    if(ak>1)
                    {
                        System.out.print("^"+ak);
                    }
                    if(bk>0)
                    {
                        System.out.print("*"+res.b);
                        if(bk>1)
                        {
                            System.out.print("^"+bk);
                        }
                    }
                }
                else
                {
                    if(bk>0)
                    {
                        System.out.print(res.b);
                        if(bk>1)
                        {
                            System.out.print("^"+bk);
                        }
                    }
                }
                ak--;
                bk++;
                pk++;
                if(bk>res.power) break;
            }
            System.out.println();
        }
    }

    public static data getFromString(String st)
    {
        data d=new data();
        String a,b,k;
        a="";
        b="";
        k="";
        int len=st.length();
        int i;
        for(i=1;i<len;i++)
        {
            if(st.charAt(i)=='+') break;
            a=a+st.charAt(i);
        }
        for(i=i+1;i<len;i++)
        {
            if(st.charAt(i)==')') break;
            b=b+st.charAt(i);
        }
        for(i=i+2;i<len;i++)
        {
            k=k+st.charAt(i);
        }
        d.a=a;d.b=b;d.power=Integer.valueOf(k);
        return d;
    }
}

class data
{
    String a,b;
    int power;
}

