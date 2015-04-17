package com.levneiman.alg_cmp;

import com.levneiman.alg_cmp.Problems.Problem;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import static com.levneiman.alg_cmp.Problems.SO;


/**
 * Created by lneiman on 4/10/15.
 */
public class GCJ_2015 {
  public static class QualificationRound {
    public static class A implements Problem {

      @Override
      public void solve(InputStream in, PrintStream out)
          throws Exception {
        Scanner scanner = new Scanner(in);
        int T = scanner.nextInt();
        for (int CASE = 1; CASE <=T; ++CASE) {
          Problems.SO.println("====");
          int sMax = scanner.nextInt();
          String S = scanner.next();
          int invite = 0;
          int ovating = 0;
          for (int i = 0; i < S.length(); ++i) {
            int sI = S.charAt(i) - '0';
            Problems.SO.println(String.format("Ovating %d, i %d, invite %d", ovating, i, invite));
            if (i <= ovating) {
              ovating += sI;
            } else {
              Problems.SO.println("Need to invite");
              invite += i - ovating;
              ovating += i - ovating + sI;
            }
          }
          out.println(String.format("Case #%d: %d", CASE, invite));
        }

      }
    }
    public static class B implements Problem {

      static final int INF = (int)1e6;

      Comparator<Integer> reverse = new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
          return -1 * o1.compareTo(o2);
        }
      };

      // magic min, min min, max el after
      static int S[][] = new int[1001][3];
      static {
        for (int i = 0; i < S.length; ++i) {
          for (int j = 0; j < S[i].length; ++j) {
            S[i][j] = INF;
          }
        }

        S[0][0] = S[0][1] = S[0][2] = 0;
        S[1][0] = 0;
        S[1][1] = 1;
        S[1][2] = 0;
        S[2][0] = 0;
        S[2][1] = 2;
        S[2][2] = 0;
        S[3][0] = 0;
        S[3][1] = 3;
        S[3][2] = 0;

        computeNumber(14);
        computeNumber(6);
        computeNumber(4);

        for (int i = 4; i <= 14; ++i) {
          SO.println(String.format("%d - %s", i, Problems.Util.PrettyPrint.print(S[i])));
        }
      }

      static int [] computeNumber(int num) {
        if (S[num][1] != INF) return S[num];
        for (int i = 1; i <= num /2 ; ++i) {
          int [] left = computeNumber(i);
          int [] right = computeNumber(num-i);
          int moves = (num % 2 == 0 ? 0 : 1) +  Math.max(left[0], right[0]) + Math.max(left[1], right[1]);
          if (S[num][1] > moves) {
            SO.println(String.format("Maybe %d - %d:%s %d:%s - moves %d", num,
                    i,
                    Problems.Util.PrettyPrint.print(left),
                    num -i,
                    Problems.Util.PrettyPrint.print(right),moves));
            S[num][0] = 1 + Math.max(left[0], right[0]);
            S[num][1] = moves;
            S[num][2] = Math.max(i, num -i);
          }
        }
        return S[num];
      }


      int solve(int cost, List<Integer> list, int min) {
        //Problems.SO.println(list);
        int max = list.get(0);
        //Problems.SO.println(String.format("cost %d, max %d", cost, max));

        if (cost >= max) return cost+max;

        int ret = cost + max;
        for (int i = max % 2 == 0 ? max / 2 : max / 2 + 1; i < max; ++i) {
          List<Integer> subList = new ArrayList<>(list.subList(1, list.size()));
          subList.add(max - i);
          subList.add(i);
          subList.sort(reverse);
          ret = Math.min(solve(cost+1, subList, min), ret);
        };

        return ret;

      }

      @Override
      public void solve(InputStream in, PrintStream out)
          throws Exception {
        Scanner scanner = new Scanner(in);
        int T = scanner.nextInt();
        for (int CASE = 1; CASE <=T; ++CASE) {
          Problems.SO.println("====");
          int D = scanner.nextInt();
          List<Integer> plates = new LinkedList<Integer>();
          for (int i = 0; i < D; ++i) plates.add(scanner.nextInt());
          plates.sort(reverse);
          Problems.SO.println(plates);

          String answer = String.format("Case #%d: %d", CASE, solve(0, plates, Integer.MAX_VALUE));
          Problems.SO.println(answer);
          out.println(answer);
        }

      }
    }

    public static class C implements Problem {

      static final int I = 2;
      static final int J = 3;
      static final int K = 4;

      static final int []M =
          {1, I, J, K,
          I, -1, K, -J,
          J, -K, -1, I,
          K, J, -I, -1
      };

      static int ident(int cc) {
        char c = (char)cc;
        switch (c) {
          case 'i':
            return I;
          case 'j':
            return J;
          case 'k':
            return K;
        }
        return -1;
      }

      static int mult(int i, int j) {
        //Problems.SO.println(i + "--"+j);
        //int ret = M[Math.abs(i)-1][Math.abs(j)-1];
        int ret = M[(Math.abs(i)-1) * 4 + (Math.abs(j)-1)];
        if (i < 0 && j > 0) ret *= -1;
        if (j < 0 && i > 0) ret *= -1;
        return ret;
      }

      static int mult(int nums[], int start, int end) {
        int ret = 1;
        for (int i = start; i < end; ++i) {
         // SO.println(String.format("ret - %d, num[i] - %d", ret, nums[i]));
          ret = mult(ret, nums[i]);
        }
        return ret;
      }


      class BooleanCnt {
        boolean cunt;
      }

      boolean brute(int X, String str) {
        if (str.length() == 1 ) return false;
        if (str.chars().distinct().count() == 1 ) return false;
        String m = "";
        for (int i = 0; i < X; ++i) {
          m += str;
        }

        final int [] ints = m.chars().map(C::ident).toArray();

        final BooleanCnt ret = new BooleanCnt();
        ret.cunt = false;

        IntStream.range(1, m.length()).parallel().forEach(i -> {
          int ii = mult(ints, 0, i );
          if (ii == I) {
            IntStream.range(i + 1, ints.length).forEach(j -> {
              int jj = mult(ints, i, j);
              if (jj == J && mult(ints, j, ints.length) == K) {
                ret.cunt = true;
              }
            });
          }
        });


        /*
        for (int i = 1; i < m.length(); ++i) {

          for (int j = i + 1; j < m.length(); ++j) {
            int ii = mult(ints, 0, i);
            SO.println(String.format("i %d ii %d", i, ii));
            if (ii != I) continue;
            int jj = mult(ints, i, j);
            if (jj != J) continue;
            int kk = mult(ints, j, m.length());
            if (kk != K) continue;
            return true;

          }
        }
        */
        return ret.cunt;

      }

      @Override
      public void solve(InputStream in, PrintStream out)
          throws Exception {
        Scanner scanner = new Scanner(in);
        int T = scanner.nextInt();
        for (int CASE = 1; CASE <= T; ++CASE) {
          SO.println("Doing case " + CASE);
          int L, X;
          L = scanner.nextInt();
          X = scanner.nextInt();
          String str = scanner.next();
          SO.println("string - " + str);
          SO.println("X - " + X);
          out.println(String.format("Case #%d: %s", CASE, brute(X, str) ? "YES" : "NO"));
        }
      }
    }

    public static class D implements Problem {

      @Override
      public void solve(InputStream in, PrintStream out)
          throws Exception {
        Scanner scanner = new Scanner(in);
        int T = scanner.nextInt();
        for (int CASE = 1; CASE <= T; ++CASE) {
          int X, R, C;
          X = scanner.nextInt();
          R = scanner.nextInt();
          C = scanner.nextInt();
          boolean canFit = true;
          if (X >= 7) canFit = false;



          out.println(String.format("Case #%d: %s", CASE, canFit ? "GABRIEL" : "RICHARD"));
        }

      }
    }
  }
}
