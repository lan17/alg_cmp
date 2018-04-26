package com.levneiman.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class GenerateParentheses {
  static class SolutionA {
    void compute(int n, String str, int s, int c, List<String> accumulator) {
      if (str.length() == n * 2) {
        accumulator.add(str);
      }
      if (s < n) {
        compute(n, str + "(", s + 1, c, accumulator);
      }
      if (c < s) {
        compute(n, str + ")", s, c + 1, accumulator);
      }
    }

    public List<String> generateParenthesis(int n) {
      List<String> accumulator = new LinkedList<>();
      compute(n, "", 0, 0, accumulator);
      System.out.println(accumulator.size());
      return accumulator;
    }
  }

  static class SolutionB {
    Set<String> answers [];

    Set<String> compute(int n) {
      if (n == 1) {
        return answers[1];
      }
      Set<String> solutions = answers[n];
      if (!solutions.isEmpty()) {
        return solutions;
      }

      Set<String> subCombos = compute(n -1);
      String a = "()%s";
      String b = "(%s)";
      String c = "%s()";

      for (String subSolution : subCombos) {
        solutions.add(String.format(a, subSolution));
        solutions.add(String.format(b, subSolution));
        solutions.add(String.format(c, subSolution));
      }

      if (n % 2 == 0) {
        for (String subSolution : compute(n/2)) {
          solutions.add(String.format("%s%s", subSolution, subSolution));
        }
      }
      return solutions;
    }

    public List<String> generateParenthesis(int n) {
      answers = new Set[n + 1];
      for (int i = 0; i <=n; i++) answers[i] = new TreeSet<>();
      answers[1].add("()");

      List<String> ret = new ArrayList<>(compute(n));
      System.out.println(ret.size());
      return ret;
    }
  }


  public static void main(String [] args) {
    System.out.println(new SolutionA().generateParenthesis(4));
    System.out.println(new SolutionB().generateParenthesis(4));
  }
}
