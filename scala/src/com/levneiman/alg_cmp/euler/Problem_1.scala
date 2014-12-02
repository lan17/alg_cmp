package com.levneiman.alg_cmp.euler

object Main {
  def main(args: Array[String]) {
    val answer = (for (i <- 1 until 1000 if i % 3 == 0 || i % 5 == 0 ) yield i).sum
    println(answer)
  }
}