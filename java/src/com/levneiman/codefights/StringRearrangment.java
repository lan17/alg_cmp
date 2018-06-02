// https://codefights.com/arcade/intro/level-7/PTWhv2oWqd6p4AHB9/description
package com.levneiman.codefights;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;

public class StringRearrangment {
  // Comparator which ignores character at position skip when comparing two strings.
  Comparator<String> makeComparator(final int skip) {
    return (a, b) -> {
      for (int i = 0; i < a.length(); i++) {
        if (i == skip) continue;
        if (a.charAt(i) < b.charAt(i)) {
          return -1;
        } else if (a.charAt(i) > b.charAt(i)) {
          return 1;
        }
      }
      return 0;
    };
  }

  boolean canCoverAll(
      String[] input,
      int current,
      Set<Integer> visited,
      TreeMap<String, Set<Integer>> graph[],
      int m,
      int n) {
    if (visited.contains(current)) {
      return false;
    }

    visited.add(current);
    if (visited.size() == n) {
      return true;
    }

    for (int i = 0; i < m; i++) {
      Set<Integer> neighbors = new HashSet<>(graph[i].get(input[current]));
      neighbors.removeAll(visited);

      for (Integer neigbhor : neighbors) {
        if (input[current].equals(input[neigbhor])) {
          continue;
        }

        if (canCoverAll(input, neigbhor, visited, graph, m, n)) {
          return true;
        }
      }
    }

    visited.remove(current);
    return false;
  }

  boolean stringsRearrangement(String[] inputArray) {
    int m = inputArray[0].length();
    int n = inputArray.length;

    // Compute graph of strings.
    // graph[i][str] points to set of strings that are same except for character at position i.
    TreeMap<String, Set<Integer>> graph[] = new TreeMap[m];
    for (int i = 0; i < m; i++) {
      graph[i] = new TreeMap<>(makeComparator(i));

      for (int j = 0; j < n; j++) {
        Set<Integer> siblings = graph[i].get(inputArray[j]);
        if (siblings == null) {
          siblings = new HashSet<>();
        }
        siblings.add(j);
        graph[i].put(inputArray[j], siblings);
      }
    }

    // See if we can cover all words using backtracking and starting at word i.
    for (int i = 0; i < n; i++) {
      if (canCoverAll(inputArray, i, new HashSet<>(), graph, m, n)) {
        return true;
      }
    }
    return false;
  }
}
