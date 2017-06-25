

public class BitwiseSubtract {


	static int subtract(int x, int y)
	{
	   
	    while (y != 0)// no carry found
	    {
	        // borrow contains common set bits of y and unset bits of x
	        int borrow = (~x) & y;
	 
	        // x xor y
	        x = x ^ y;
	 
	        // Borrow is shifted by one so that subtracting it from
	        // x gives the required sum
	        y = borrow << 1;
	    }
	    return x;
	}
	
	public static void main(String args[]){
	int x=29, y=10;
	System.out.println("x-y is " + subtract(x,y));
	}
	
}
