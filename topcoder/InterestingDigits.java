import java.math.*;
import java.util.*;

public class InterestingDigits
{
	boolean isInteresting( int digit, int base )
	{
		for( int m = 2; m <= 1000; ++m )
		{
			Integer multi = digit * m;
			String base_rep = Integer.toString( multi, base );
			int sum = 0;
			for( int i = 0; i < base_rep.length(); ++i )
			{
				sum += Integer.parseInt( ""+ base_rep.charAt(i), base );
				
			}			
			if( sum % digit != 0 ) return false;
		}
		return true;
	}

	public int[] digits(int base)
	{
		Vector<Integer> ans = new Vector<Integer>();
		for( int d = 2; d < base; ++d )
		{
			if( isInteresting( d, base ) ) ans.add( d );
		}
		int[] ret = new int[ans.size()];
		for( int i = 0; i < ans.size(); ++i )ret[i]=ans.get(i);
		return ret;
	}
}
