package com.levneiman.leetcode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class SlidingWindowMaximum {
  class Solution {

    void increment(Map<Integer, Integer> counts, int x) {
      Integer count = counts.get(x);
      if (count == null) {
        count = 0;
      }
      count++;
      counts.put(x, count);
    }

    int decrement(Map<Integer, Integer> counts, int x) {
      Integer ret = counts.get(x);
      --ret;
      counts.put(x, ret);
      return ret;
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
      if (nums.length == 0) {
        return new int[0];
      }
      PriorityQueue<Integer> heap =
          new PriorityQueue<>(
              nums.length,
              (o1, o2) -> -1 * o1.compareTo(o2));
      Map<Integer, Integer> counts = new HashMap<>(nums.length);

      int[] maxes = new int[nums.length - k + 1];

      for (int i = 0; i < k; i++) {
        heap.add(nums[i]);
        increment(counts, nums[i]);
      }
      maxes[0] = heap.peek();

      for (int i = k; i < nums.length; i++) {
        decrement(counts, nums[i-k]);
        increment(counts, nums[i]);

        if (counts.get(nums[i]) == 1) heap.add(nums[i]);

        while (counts.get(heap.peek()) == 0) {
          heap.poll();
        }

        maxes[i - k + 1] = heap.peek();
      }

      return maxes;
    }
  }
}
