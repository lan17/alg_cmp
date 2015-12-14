// // BEGIN CUT HERE
/**
 // PROBLEM STATEMENT
// One day, Bob the Coder was wondering whether abstract programming problems can have applications in practice. The next day, he was selected to be on a quiz show. He will win one million dollars if he answers the following question:

Given a int[] A with N elements and an int K, count the number of tuples (p, q, r) such that 0 <= p < q < r < N and A[p] * A[q] * A[r] is divisible by K.

Please compute and return the answer to Bob's question.

DEFINITION
Class:AnArray
Method:solveProblem
Parameters:int[], int
Returns:int
Method signature:int solveProblem(int[] A, int K)


CONSTRAINTS
-A will contain between 3 and 2,000 elements, inclusive.
-K will be between 1 and 1,000,000, inclusive.
-Each element of A will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
{31, 1, 3, 7, 2, 5}
30

Returns: 1

The return value is 1 because there is exactly one valid tuple. The tuple is (2, 4, 5). It is valid because A[2] * A[4] * A[5] = 3 * 2 * 5 = 30.

1)
{4, 5, 2, 25}
100

Returns: 2



2)
{100000000, 100000000, 100000000}
1000000

Returns: 1

Note that the product A[p] * A[q] * A[r] doesn't have to fit into a 64-bit integer variable.

3)
{269, 154, 94, 221, 171, 154, 50, 210, 258, 358, 121, 159, 8, 47, 290, 125, 291, 293, 338, 248, 295, 160, 268, 227, 99, 4, 273}
360

Returns: 114



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
1

Returns: 220



 **/
// // END CUT HERE
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;


public class AnArray {
  public static final PrintStream out = System.out;

  static boolean isPrime[] = new boolean[1000000];
  static TreeSet<Integer> primes = new TreeSet<Integer>();

  static {
    for (int i = 0; i < isPrime.length; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < isPrime.length; ++i) {
      if (isPrime[i]) {
        primes.add(i);
        for (int j = 2; i *j < isPrime.length; ++j) {
          isPrime[i*j] = false;
        }
      }
    }
  }

  BigInteger primeFactors(int num, BigInteger already) {
    if (num == 0) return already;
//    out.println(num);
    for (Integer prime : primes) {
      if (num % prime == 0) {
        already = already.setBit(prime);
        already = already.or(primeFactors(num / prime, already));
      }
    }
    return already;
  }

  public int solveProblem(int[] A, int K) {
    TreeSet<BigInteger> factors = new TreeSet<BigInteger>();
    for (int i = 0; i < A.length; ++i) {
      factors.add(primeFactors(A[i], BigInteger.ZERO));
    }
    return 5;
  }

  public static void main(String [] args) {
    int [] nums = new int [2000];
    for (int i = 2; i < nums.length; ++i) nums[i] = i;

    long start = System.nanoTime();
    new AnArray().solveProblem(nums, 100);
    long end = System.nanoTime();

    out.println((end-start)/1e9);
  }
}
