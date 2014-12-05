import scala.language.implicitConversions
import scala.language.postfixOps
import collection.mutable.Map

object Main {
  object Fun {
    // memoize an arbitrary Function1
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

  def Problem_1(args: Array[String]) = {
    (for (i <- 1 until 1000 if i % 3 == 0 || i % 5 == 0) yield i).sum
  }

  def Problem_2(args: Array[String]) = {
    val limit = args(0).toInt
    (for (i <- Fun.fibs takeWhile (_ < limit) if i < limit && i % 2 == 0) yield i).sum
  }

  def Problem_3(args: Array[String]) = {
    Fun.Primes.primeFactors(args(0).toLong).max
  }

  def Problem_7(args: Array[String]) = {
    // https://primes.utm.edu/howmany.html ;)
    Fun.Primes.makePrimes(1000000)(10000)
  }

  def printPrimes(args: Array[String]) = {
    Fun.Primes.makePrimes(args(0).toInt).length
  }

  def printPrimeFactors(args: Array[String]) = {
    Fun.Primes.primeFactors(args(0).toInt)
  }

  def main(args: Array[String]) {

    //def wrapIt[A,R](func: A => R):(A=>R) = RunIt(TimeFunc(func))
    val wrapIt = RunIt _ compose TimeFunc _

    // implicitly convert ints to string to help with putting ints as strings as keys in the problems map
    implicit def intToString(i: Int) = i.toString

    val problems = Map[String, Array[String] => Any]()
    problems put (1, Problem_1 _)
    problems put (2, Problem_2 _)
    problems put (3, Problem_3 _)
    problems put (7, Problem_7 _)
    problems put ("primes", printPrimes _)
    problems put ("primeFactors", printPrimeFactors _)

    // wrap each solution function with timing logic
    problems.keySet.foreach((k: String) => {
      problems get k match {
        case Some(func) => problems.put(k, wrapIt(func))
        case None => println("what")
      }
    })

    problems get args(0) match {
      case Some(i) => i(args.tail)
      case None => println("shit i didn't solve that one yet :/")
    }
  }
}