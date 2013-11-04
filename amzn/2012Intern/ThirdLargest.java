import java.util.*;

public class ThirdLargest
{
    public static void main(String[]args)
    {
        List<Integer> top3 = new ArrayList<Integer>();
        top3.add(Integer.MIN_VALUE);
        top3.add(Integer.MIN_VALUE);
        top3.add(Integer.MIN_VALUE);
        Scanner scan = new Scanner(System.in);
        while(scan.hasNextInt())
        {
            int x = scan.nextInt();
            if( x > top3.get(0) )
            {
                top3.set(0,x);
                Collections.sort(top3);
            }

        }
        System.out.println(top3.get(0));
    }
}
