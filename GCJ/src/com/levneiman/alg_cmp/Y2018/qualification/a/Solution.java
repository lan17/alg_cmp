package com.levneiman.alg_cmp.Y2018.qualification.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Solution {

  static int damage(char [] chars) {
    int d = 0;
    int s = 1;
    for (Character c : chars) {
      if (c == 'S') {
        d += s;
      }
      if (c == 'C') {
        s *= 2;
      }
    }
    return d;
  }

  public static int solve(int D, String instructions) {
    int answer = 0;
    char [] chars = instructions.toCharArray();

    int damage = damage(chars);
    if (damage > D) {
      int sCount = instructions.length() - instructions.replace("S", "").length();
      //System.out.println(String.format("%s, %d, %d", instructions, D, sCount));
      if (sCount > D) {
        return -1;
      }

      while(true) {
        for (int i = chars.length - 1; i > 0; i--) {
          if (chars[i] == 'S' && chars[i - 1] == 'C') {
            // swap
            char t = chars[i];
            chars[i] = chars[i - 1];
            chars[i - 1] = t;
            answer++;

            if (damage(chars) <= D) {
              return answer;
            }
          }
        }
      }
    }
    return answer;
  }

  public static void main(String [] args) throws FileNotFoundException {
    PrintStream out = System.out;
    //Scanner scanner = new Scanner(new File(args[0]));
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();

    for (int CASE = 1; CASE <= T; ++CASE) {
      int D = scanner.nextInt();
      String instructions = scanner.next();


      int solution = solve(D, instructions);
      out.println(String.format("Case #%d: %s", CASE, solution == -1 ? "IMPOSSIBLE" : Integer.toString(solution) ));
    }

  }
}
