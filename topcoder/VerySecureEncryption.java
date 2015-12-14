// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are going to send a message to your friend.
The message is given as the String message.
To confuse potential eavesdroppers, you are going to scramble the message.


Scrambling of a message is performed using the int[] key.
If a letter is at the (0-based) position i in the original message, it will appear at the position key[i] in the scrambled message.
(The constraints given below guarantee that this process will produce a valid scrambled message.)


To make the encryption even more confusing, you are going to repeat the above process K times in a row.
Given message, key, and the int K, find and return the final encrypted message.

DEFINITION
Class:VerySecureEncryption
Method:encrypt
Parameters:String, int[], int
Returns:String
Method signature:String encrypt(String message, int[] key, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-message will contain N characters.
-Each character of message will be a lowercase English letter.
-key will contain N elements.
-Each element of key will be between 0 and N-1, inclusive.
-The elements of key will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
"abc"
{1,2,0}
1

Returns: "cab"


The character 'a' will go from position 0 to position key[0]=1.
The character 'b' will go from position 1 to position key[1]=2.
The character 'c' will go from position 2 to position key[2]=0.


1)
"abcde"
{4, 3, 2, 1, 0}
1

Returns: "edcba"



2)
"abcde"
{4, 3, 2, 1, 0}
2

Returns: "abcde"

This is the same message and the same key as in example 1, but now K=2, so we scramble the message twice.
For this particular key we see that each scrambling reverses the order of letters, which means that the final message is the same as the original we started with.

3)
"uogcodlk"
{4, 3, 6, 2, 5, 1, 0, 7}
44

Returns: "goodluck"



**/
// END CUT HERE
import java.util.*;
public class VerySecureEncryption {
	public String encrypt(String message, int[] key, int K) {
		char [] buff = message.toCharArray();
		char [] buff2 = new char[key.length];
		char [] curr = buff2;
		char [] prev = buff;
		for (int i = 0; i < K; ++i) {
			for (int j = 0; j < key.length; ++j) {
				curr[key[j]] = prev[j];
			}
			curr = curr == buff2 ? buff : buff2;
			prev = prev == buff2 ? buff : buff2;
		}
		System.out.println(new String(buff));
		System.out.println(new String(buff2));
		return new String(curr == buff ? buff2 : buff);
	}
}
