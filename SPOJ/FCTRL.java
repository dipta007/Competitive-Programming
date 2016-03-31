import java.math.*;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner stdin=new Scanner(System.in);
			BigInteger b=new BigInteger("1");
			int a;
			int n=stdin.nextInt();
			while(n!=0){
			a=stdin.nextInt();
			for (int i = 1; i <= a; i++) {
		           b = b.multiply(new BigInteger(i + ""));
		       }
			System.out.println(b);
			b= new BigInteger("1");
			n--;
			}






	}


}
