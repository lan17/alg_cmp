package com.levneiman.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.TreeMap;
import java.util.TreeSet;

public class CountofSmallerNumbersAfterSelf {
  static class Solution {
    public List<Integer> countSmaller(int[] nums) {
      int n = nums.length;
      ArrayList<Integer> sorted = new ArrayList<>(n);
      int sortedSize = 0;


      LinkedList<Integer> ret = new LinkedList<Integer>();

      for (int i = n - 1; i >= 0; i--) {
        int k;
        if (sorted.size() == 0) {
          k = 0;
        }
        else {
          k = Collections.binarySearch(sorted, nums[i]);
          if (k < 0) {
            k *= -1;
            k--;
          }
          while (k >0 && sorted.get(k - 1) >= nums[i]) --k;
        }

        sorted.add(k, nums[i]);
        ret.offerFirst(k);
      }

      return ret;
    }
  }

  public static void main(String[] args) {
    Random random = new Random();

    int[] data = new int[23000];
    for (int i = 0; i < data.length; i++) {
      data[i] = random.nextInt() % 10000;
    }

    long startTime = System.currentTimeMillis();

    Solution solution = new Solution();
    List<Integer> ret = solution.countSmaller(data);

    System.out.println(
        String.format("It took %f seconds", (System.currentTimeMillis() - startTime) / 1000.0));
  }
}
