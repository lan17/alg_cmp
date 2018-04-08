package com.levneiman.alg_cmp.Y2018.qualification.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

  public static void main(String[] args) throws FileNotFoundException {
    PrintStream out = System.out;
    //Scanner scanner = new Scanner(new File(args[0]));
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();

    for (int CASE = 1; CASE <= T; ++CASE) {
      int N = scanner.nextInt();

      int Va[] = new int[N % 2 == 1 ? N / 2 + 1 : N / 2];
      int Vb[] = new int[N / 2];
      int VV []= new int[N];
      for (int i = 0; i < N; i++) {
        int[] V = i % 2 == 0 ? Va : Vb;
        V[i / 2] = scanner.nextInt();
        VV[i] = V[i/2];
      }
      //System.out.println(Arrays.toString(Va));
      //System.out.println(Arrays.toString(Vb));
      Arrays.sort(Va);
      Arrays.sort(Vb);

      int V[] = new int [N];
      for (int i = 0; i < N; i++) {
        V[i] = i % 2 == 0 ? Va[i/2] : Vb[i/2];
      }
      Arrays.sort(VV);
      int answer = -1;
      for (int i = 0; i < N; i++) {
        if (VV[i] != V[i]) {
          answer = i;
          break;
        }

      }

      /*
      int answer = -1;
      int i = 1;
      int last = Va[0];
      while (i <= N / 2 + 1) {
        int next = i % 2 == 0 ? Va[i / 2] : Vb[i / 2];
        //System.out.println(String.format("%d, %d", last, next));
        if (next < last) {
          answer = i - 1;
          break;
        }
        last = next;
        i++;
      }
      */
      out.println(String.format(
          "Case #%d: %s",
          CASE,
          answer == -1 ? "OK" : Integer.toString(answer)));
    }


  }
}
