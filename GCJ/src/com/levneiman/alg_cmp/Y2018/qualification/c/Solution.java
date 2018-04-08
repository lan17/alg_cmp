package com.levneiman.alg_cmp.Y2018.qualification.c;

import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Solution {

  static void printCoordinate(int x, int y, PrintStream out) {
    out.println(String.format("%d %d", x, y));
    out.flush();
  }

  static int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  static int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

  static boolean goodSquare(int x, int y, boolean board[][]) {
    for (int d = 0; d < dx.length; d++) {
      int i, j;
      i = x + dx[d];
      j = y + dy[d];

      if (!board[i][j]) {
        return false;
      }
    }
    return true;
  }

  static void solve(Scanner scanner, OutputStream outStream) {
    PrintStream out = new PrintStream(outStream);

    boolean[][] board = new boolean[1000][1000];

    int A = scanner.nextInt();

    System.err.println("A is ");
    System.err.println(A);

    int soFar = 0;

    int i;
    int j;
    j = 500;
    i = 5;

    while (soFar < A) {
      printCoordinate(i, j, out);
      printCoordinate(i, j, System.err);
      //System.err.println(soFar);
      int x = scanner.nextInt();
      int y = scanner.nextInt();

      if (x == -1 || y == -1) {
        System.err.println("WTF!");
        System.exit(-1);
        return;
      }
      if (x == 0 && y == 0) {
        return;
      }
      board[x][y] = true;
      if (goodSquare(i, j, board)) {
        soFar += 9;
        i += 3;
      }
    }

  }

  public static void main(String[] args) throws FileNotFoundException {
    PrintStream out = System.out;
    Scanner scanner = new Scanner(System.in);
    //Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    System.err.println(T);

    for (int CASE = 1; CASE <= T; ++CASE) {
      solve(scanner, System.out);
    }
  }
}
