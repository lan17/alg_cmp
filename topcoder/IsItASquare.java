// // BEGIN CUT HERE
/**
 // PROBLEM STATEMENT
// It's a bird! It's a plane! No, it's a square in a plane! Wait, is it really a square?


There are four distinct points in the plane.
You are given their coordinates in the int[]s x and y:
for each i between 0 and 3, inclusive, there is a point at (x[i], y[i]).


Return "It's a square" (quotes for clarity) if the four points are the vertices of a square.
Otherwise, return "Not a square".

DEFINITION
Class:IsItASquare
Method:isSquare
Parameters:int[], int[]
Returns:String
Method signature:String isSquare(int[] x, int[] y)


CONSTRAINTS
-x will contain 4 elements.
-y will contain 4 elements.
-Each element of x will be between 0 and 10,000, inclusive.
-Each element of y will be between 0 and 10,000, inclusive.
-The four points described by x and y will be distinct.


EXAMPLES

0)
{0, 0, 2, 2}
{0, 2, 0, 2}

Returns: "It's a square"



1)
{0, 1, 5, 6}
{1, 6, 0, 5}

Returns: "It's a square"

Note that the sides of the square do not have to be parallel to the coordinate axes.
Also note that the order in which the points are given does not have to be the same as the order in which you would encounter them when following the boundary of the square.

2)
{0, 0, 7, 7}
{0, 3, 0, 3}

Returns: "Not a square"



3)
{0, 5000, 5000, 10000}
{5000, 0, 10000, 5000}

Returns: "It's a square"



4)
{1, 2, 3, 4}
{4, 3, 2, 1}

Returns: "Not a square"



5)
{0, 5, 3, 8}
{0, 0, 4, 4}

Returns: "Not a square"



 **/
// // END CUT HERE
import java.io.PrintStream;
import java.util.*;
import javafx.util.Pair;


public class IsItASquare {
  public static final PrintStream out = System.out;

  double distance(int x, int y, int x1, int y1) {
    return Math.sqrt(Math.pow(x1-x,2) + Math.pow(y1 -y, 2));
  }

  TreeSet<Double> getSidez(double [][] distances, int el) {
    TreeSet<Double> ret = new TreeSet<Double>();
    for (int j = 0; j < 4; ++j) {
      if (j == el) continue;
      ret.add(distances[el][j]);
    }
    return ret;
  }

  boolean doubleEqual(double a, double b, double eps) {
    return Math.abs(a - b) <= eps;
  }

  public String isSquare(int[] x, int[] y) {

    double [][] distances = new double[4][4];

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        distances[i][j] = distances[j][i] = distance(x[i], y[i], x[j], y[j]);
      }
    }

    boolean isSquare = true;

    TreeSet<Double> sidez = getSidez(distances, 0);
    out.println(sidez);
    if (sidez.size() != 2) {
      isSquare = false;
    }
    if (isSquare) {
      for (int i = 1; i < 4; ++i) {
        TreeSet<Double> otherSidez = getSidez(distances, i);
        out.println(otherSidez);
        if (otherSidez.size() != 2 || !doubleEqual(otherSidez.last(), sidez.last(), 1e-6) || !doubleEqual(otherSidez.first(), sidez.first(), 1e-6)) {
          isSquare = false;
          break;
        }
      }
    }

    return isSquare ? "It's a square" : "Not a square";




  }
}
