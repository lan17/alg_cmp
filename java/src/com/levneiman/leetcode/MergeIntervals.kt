package com.levneiman.leetcode

import java.util.*

class MergeIntervals {
    internal class Interval {
        var start: Int = 0
        var end: Int = 0

        constructor() {
            start = 0
            end = 0
        }

        constructor(s: Int, e: Int) {
            start = s
            end = e
        }
    }

    internal inner class Solution {
        fun merge(intervals: List<Interval>): List<Interval> {
            if (intervals.size == 0) return intervals
            Collections.sort(intervals) { o1, o2 -> Integer.compare(o1.start, o2.start) }

            val merged = LinkedList<Interval>()

            val iterator = intervals.iterator()
            merged.add(iterator.next())

            iterator.forEachRemaining { interval ->
                val lastInterval = merged.last
                if (interval.start <= lastInterval.end) {
                    lastInterval.end = Math.max(lastInterval.end, interval.end)
                } else {
                    merged.add(interval)
                }
            }

            return merged


        }
    }
}
