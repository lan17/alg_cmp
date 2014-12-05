import scala.language.implicitConversions
import scala.language.postfixOps

object Main {
  object Fun {
    // http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.Stream
    def fibs: Stream[BigInt] = BigInt(0) #:: fibs.scanLeft(BigInt(1))(_ + _)

    object Primes {
      type NT = Long
      
      def isPrime(n: NT, factors: List[NT]): Boolean = {
        factors takeWhile (_ < Math.sqrt(n)) forall (n % _ != 0)
      }

      def makePrimes(N: NT): List[NT] = {
        def rec(i: Int, primes: List[NT]): List[NT] = {
          if (i >= N) primes
          else if (isPrime(i, primes)) rec(i + 2, i :: primes)
          else rec(i + 1, primes)
        }
        rec(5, List(3, 2)).reverse
      }
    }
  }

  type A = Array[String]
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

  def printPrimes(args: Array[String]) = {
    Fun.Primes.makePrimes(args(0).toLong).length
  }

  def main(args: Array[String]) {

    //def wrapIt[A,R](func: A => R):(A=>R) = RunIt(TimeFunc(func))
    val wrapIt = RunIt _ compose TimeFunc _

    implicit def intToString(i: Int) = i.toString

    val problems = collection.mutable.Map[String, Array[String] => Any]()
    problems put (1, Problem_1 _)
    problems put (2, Problem_2 _)
    problems put ("primes", printPrimes _)

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