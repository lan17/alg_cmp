object imaptient {
  object Chapter2 {
    def signum[E](v: E)(implicit num: Numeric[E]): Int = {
      num.signum(v)
    }

    def pow[E](x: E, n: Int)(implicit num: Fractional[E]): E = {
      import num._
      if (n == 0) num.one
      else if (n > 0) {
        if (n % 2 == 0) pow(x, n / 2) * pow(x, n / 2)
        else x * pow(x, n - 1)
      } else num.div(num.one, pow(x, -n))
    }
  }

  def main(arg: Array[String]) = {
    println(Chapter2.pow(2.0d, 32))
    println(Chapter2.pow(2.0f, 64))
    println(Chapter2.pow(2.0D, 1024))
    println(Chapter2.pow(BigDecimal(2), 1024))
  }
}