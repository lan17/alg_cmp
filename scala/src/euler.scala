import scala.language.implicitConversions
import scala.language.postfixOps
import collection.mutable.Map

/**
 * Solving project euler problems using scala by Lev Neiman
 *
 * https://projecteuler.net
 */
object Main {
  object Fun {
    /**
     * memoize an arbitrary Function1
     */
    def mem1[A, R](func: A => R): (A => R) = {
      val map = Map[A, R]()
      (a: A) => {
        map get a match {
          case Some(i) => i
          case None => {
            val ret = func(a)
            map += a -> ret
            ret
          }
        }
      }
    }

    // http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.Stream
    def fibs: Stream[BigInt] = BigInt(0) #:: fibs.scanLeft(BigInt(1))(_ + _)

    /**
     * Stuff to do with testing/making prime numbers
     */
    object Primes {
      type NT = Long

      /**
       * Check if a number is prime by naively checking if its divisible by odd numbers less than its square root
       */
      def _isPrimeNaive(n: NT): Boolean = {
        if (n == 2 || n == 3) true
        else if (n % 2 == 0) false
        else (3 until (Math.sqrt(n).toInt + 2) by 2) forall (n % _ != 0)
      }

      def isPrimeNaive = mem1(_isPrimeNaive)

      def makePrimes(N: NT, isPrimeFunc: NT => Boolean): Seq[NT] = {
        for (i <- (2L until N) if (isPrimeFunc(i))) yield i
      }

      /**
       * Generate a Seq of primes less than * N
       * by default do not use memoized version of isPrime
       */
      def makePrimes(N: NT): Seq[NT] = {
        makePrimes(N, _isPrimeNaive)
      }

      // compute prime factors of a number N
      def primeFactors(N: NT): Seq[NT] = {
        def _primeFactors(N: NT, primes: Seq[NT], mem: Map[NT, List[NT]]): List[NT] = {
          mem get N match {
            case Some(factors) => factors
            case None => {
              // need to calculate
              primes.find(N % _ == 0) match {
                case Some(factor) => {
                  val ret = factor :: _primeFactors(N / factor, primes, mem)
                  mem += N -> ret
                  ret
                }
                case None => {
                  List(N)
                }
              }
            }
          }
        }

        _primeFactors(N, makePrimes(Math.sqrt(N).toInt), Map())
      }
    }
  }

  // type for arguments of euler problem implementation.
  type A = Array[String]
  // type for return value of euler problem implementation.
  type R = Any

  def RunIt(func: A => R): (A => R) = {
    (args: A) =>
      {
        val ret = func(args);
        println("Solution: %s".format(ret));
        ret
      }
  }

  /**
   * Wrap a given function of single arg with timing logic.
   */
  def TimeFunc(func: A => R): (A => R) = {
    (args: A) =>
      {
        val start = System.nanoTime
        val ret = func(args)
        println("Problem took %f seconds to solve".format((System.nanoTime - start) / 1e9))
        ret
      }
  }

  def Problem_8(args: A) = {
    def multStr(a: String): Long = a.foldLeft(1L) { (acc, c) => acc * (c - '0') }
    val in = io.Source.fromInputStream(System.in).getLines.mkString
    val slide = in sliding (args(0).toInt)
    val num = slide max (new Ordering[String] { def compare(a: String, b: String) = multStr(a) compare multStr(b) })
    println("number %s".format(num))
    multStr(num)
  }

  def main(args: A) {
    val wrapIt = RunIt _ compose TimeFunc _

    // Implicit conversions as helper methods for putting problems into map and dealing with String args
    implicit def intToString(i: Int): String = i.toString
    implicit def stringToLong(s: String) = s.toLong
    // magically chain implicits!  This line should chain conversion from string -> long -> int
    // http://stackoverflow.com/questions/5332801/how-can-i-chain-implicits-in-scala
    implicit def stringToInt[String <% Long](a: String): Int = a.toInt
    implicit def stringToBigInt[String <% Long](s: String): BigInt = BigInt(s.toString, 10)
    implicit def bigIntToString(s: BigInt) = s.toString

    val problems = Map[String, A => R]()
    problems put (1, (arg: A) => (for (i <- 1 until 1000 if i % 3 == 0 || i % 5 == 0) yield i).sum)
    problems put (2, (arg: A) => (for (i <- Fun.fibs takeWhile (_ < arg(0)) if i < arg(0) && i % 2 == 0) yield i).sum)
    problems put (3, (arg: A) => Fun.Primes.primeFactors(arg(0)).max)
    problems put (6, (arg: A) => Math.pow((1L to arg(0)).foldLeft(0L) { (acc, n) => acc + n }, 2L).toLong - (1L to arg(0)).foldLeft(0L) { (acc, n) => acc + n * n })
    // https://primes.utm.edu/howmany.html ;)
    problems put (7, (arg: A) => Fun.Primes.makePrimes(1000000)(10000))
    problems put (8, Problem_8 _)
    problems put (10, (arg: A) => Fun.Primes.makePrimes(arg(0)).sum)
    problems put (13, (arg: A) => io.Source.fromInputStream(System.in).getLines.foldLeft(BigInt("0", 10)) { (acc, c) => acc + BigInt(c, 10) }.subSequence(0, 10))
    problems put (16, (arg: A) => BigInt(2, 10).pow(arg(0)).toString.foldLeft(0) { (acc, n) => acc + n - '0' })
    problems put ("primes", (arg: A) => Fun.Primes.makePrimes(arg(0)).length)
    problems put ("primeFactors", (arg: A) => Fun.Primes.primeFactors(arg(0)))

    // wrap each solution function with timing logic
    problems.keySet.foreach((k: String) => {
      problems get k match {
        case Some(func) => problems.put(k, wrapIt(func))
        case None => println("what")
      }
    })

    // execute the problem user selected
    problems get args(0) match {
      case Some(i) => i(args.tail)
      case None => println("shit i didn't solve that one yet :/")
    }
  }
}