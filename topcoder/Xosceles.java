// BEGIN CUT HERE
// PROBLEM STATEMENT
// Little Johnny loves triangles and loves ascii art, but above of all things, loves the character 'X'. His drive to mix these passions together has lead him to invent the Xosceles - Isosceles triangles made completely of 'X' characters. To draw a Xosceles, Little Johnny opens a text editor begins by typing "X" or "XX" (quotes for clarity) in the middle of the first line of the text document, he follows by typing 3 or 4 'X' characters in the following line, in such a way that the second line contains 2 more 'X' characters than the first one. He continues this process until he gets tired, making sure to align each line to the center (so that it forms an isoceles triangle).

Some example results of this process follow: (For convenience, '.' characters are used instead of whitespace):

....X....
...XXX...
..XXXXX..
.XXXXXXX.
XXXXXXXXX

...XX...
..XXXX..
.XXXXXX.
XXXXXXXX

.X.
XXX



Little Johnny has challenged you to draw a Xosceles using exactly xCount 'X' characters. Return a String[] that contains xCount characters and follows the rules stated above. The first element of your return value would represent the first line. All lines in the return must have the same length. Use '.' to represent whitespace, and make sure that your return value contains as little whitespace as possible. In case it is not possible to draw one of such triangles using xCount 'X' characters, return an empty String[].


DEFINITION
Class:Xosceles
Method:draw
Parameters:int
Returns:String[]
Method signature:String[] draw(int xCount)


CONSTRAINTS
-xCount will be between 3 and 2550, inclusive.


EXAMPLES

0)
4

Returns: {".X.", "XXX" }



1)
6

Returns: {".XX.", "XXXX" }



2)
16

Returns: {"...X...", "..XXX..", ".XXXXX.", "XXXXXXX" }



3)
18

Returns: { }

It is not possible to make a triangle with 18 'X' characters.

4)
100

Returns: {".........X.........", "........XXX........", ".......XXXXX.......", "......XXXXXXX......", ".....XXXXXXXXX.....", "....XXXXXXXXXXX....", "...XXXXXXXXXXXXX...", "..XXXXXXXXXXXXXXX..", ".XXXXXXXXXXXXXXXXX.", "XXXXXXXXXXXXXXXXXXX" }



// END CUT HERE
import java.util.*;
public class Xosceles {
	public String[] draw(int xCount) {
		
	}
	public static void main(String[] args) {
		Xosceles temp = new Xosceles();
		System.out.println(temp.draw(int xCount));
	}
}
