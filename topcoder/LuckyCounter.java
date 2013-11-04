/*
// PROBLEM STATEMENT
// Suppose that we're given a moment of time written as HH:MM, where HH is the hour and MM is the minutes. Let's say that this moment is lucky if it is formatted AB:AB, AA:BB or AB:BA, where both occurrences of A stand for the same digit and both occurrences of B also stand for the same digit. It is allowed for the digits represented by A and B to be the same as well.
You are given a String[] moments, where each element represents a single moment of time. Return how many of these time moments are lucky.


DEFINITION
Class:LuckyCounter
Method:countLuckyMoments
Parameters:String[]
Returns:int
Method signature:int countLuckyMoments(String[] moments)


CONSTRAINTS
-moments will contain between 1 and 50 elements, inclusive.                                                              
-Each element of moments will be formatted "HH:MM" (quotes for clarity), where HH is between 00 and 23, inclusive, and MM is between 00 and 59, inclusive.


EXAMPLES

0)
{"12:21", "11:10"}

Returns: 1

12:21 is lucky, while 11:10 is not.

1)
{"00:00", "00:59", "23:00"}

Returns: 1

Only 00:00 is lucky here (note that it is formatted AB:AB, AA:BB and AB:BA at the same time).

2)
{"12:34"}

Returns: 0



3)
{"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"}

Returns: 3



*/
import java.util.*;
public class LuckyCounter {
	public int countLuckyMoments(String[] moments) {
		
	}
	public static void main(String[] args) {
		LuckyCounter temp = new LuckyCounter();
		System.out.println(temp.countLuckyMoments(String[] moments));
	}
}
