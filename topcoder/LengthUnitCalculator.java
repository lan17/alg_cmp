// // BEGIN CUT HERE
/**
 // PROBLEM STATEMENT
// Your task is to write a calculator that will convert between four different length units: inches (in), feet (ft), yards (yd), and miles (mi).

The conversions between these units:

1 ft = 12 in
1 yd = 3 ft
1 mi = 1760 yd


You are given an int amount and Strings fromUnit and toUnit.
Compute and return the amount of toUnits that corresponds to amount fromUnits.
(For example, if amount=41, fromUnit="mi", and toUnit="in", you are supposed to compute the number of inches in 41 miles.)

Note that the result will not necessarily be an integer.

DEFINITION
Class:LengthUnitCalculator
Method:calc
Parameters:int, String, String
Returns:double
Method signature:double calc(int amount, String fromUnit, String toUnit)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-amount will be between 1 and 1,000, inclusive.
-fromUnit will be one of {"in", "ft", "yd", "mi"}.
-toUnit will be one of {"in", "ft", "yd", "mi"}.


EXAMPLES

0)
1
"mi"
"ft"

Returns: 5280.0

We are asked to convert 1 mile into feet.
From the information in the statement we know that 1 mi = 1760 yd = (1760 * 3) ft = 5280 ft.

1)
1
"ft"
"mi"

Returns: 1.893939393939394E-4

Here we have 1 ft = 1/5280 mi, which is approximately 0.000189394 miles.

2)
123
"ft"
"yd"

Returns: 41.0



3)
1000
"mi"
"in"

Returns: 6.336E7



4)
1
"in"
"mi"

Returns: 1.5782828282828283E-5



5)
47
"mi"
"mi"

Returns: 47.0



 **/
// // END CUT HERE
import java.io.PrintStream;
import java.util.*;


public class LengthUnitCalculator {
  public static final PrintStream out = System.out;
  static HashMap<String, Integer> index;
  static HashMap<Integer, String> reverse_index;
  static double [][] conv = {
      {1, -1, -1, 12},
      {3, 1, -1, -1},
      {-1, 1760, 1, -1},
      {1d/12d, -1, -1, 1}
  };
  static {
    index = new HashMap<String, Integer>();
    index.put("ft", 0);
    index.put("yd", 1);
    index.put("mi", 2);
    index.put("in", 3);

    reverse_index = new HashMap<Integer, String>();
    for (String key : index.keySet()) {
      reverse_index.put(index.get(key), key);
    }

    for (int i = 0; i < 4; ++i) {
      for (int j =0; j <4; ++j) {
        if (conv[i][j] == -1) {
          if (conv[j][i] != -1) {
            conv[i][j] = 1d/conv[j][i];
          }
        }
        System.out.print(conv[i][j] + ", ");
      }
      System.out.println("-");
    }
  }

  public double calc(int amount, String fromUnit, String toUnit) {
    return search(amount, fromUnit, toUnit, new HashSet<String>());

  }

  double search(double amnt, String from, String to, Set<String> visited) {
    System.out.println(String.format("%s - %s", from, to));
    if (from.equals(to)) {
      return amnt;
    }
    if (visited.contains(from)) {
      return -1;
    }
    int i = index.get(from);
    int j = index.get(to);
    if (conv[i][j] != -1) {
      return amnt *= conv[i][j];
    } else {
      for (int k = 0; k < 4; ++k) {
        if (k != i && k !=j && conv[i][k] != -1) {
          visited.add(from);
          double answer = search(amnt *= conv[i][k], reverse_index.get(k), to, visited);
          if (answer != -1 ) return answer;
        }
      }
    }
    return -1;
  }
}
