import scala.collection.mutable.Map
import scala.language.{implicitConversions, postfixOps}
import scala.reflect.ClassTag

/**
 * Solving project euler problems using scala by Lev Neiman
 *
 * https://projecteuler.net
 */
object euler {
  object Fun {
    /**
     * memoize an arbitrary Function1
     */
    def mem1[A, R](func: A => R): (A => R) = {
      val map = Map[A, R]()
      (a: A) => {
        map get a match {
          case Some(i) => i
          case None =>
            val ret = func(a)
            map += a -> ret
            ret
        }
      }
    }

    def _defaultReporter = (sec:Double) => println("it took %f seconds".format(sec))

    /**
     * Wrap a given function of single arg with timing logic.
     */
    def TimeFunc1[K,V](func: K => V, reporter: Double => Unit = _defaultReporter): (K => V) = {
      (args: K) =>
      {
        val start = System.nanoTime
        val ret = func(args)
        reporter((System.nanoTime-start)/1e9)
        ret
      }
    }

    def TimeFunc0[V](func: () => V, reporter: Double => Unit = _defaultReporter): () => V = {
      () => {
        val start = System.nanoTime
        val ret = func()
        reporter((System.nanoTime - start)/1e9)
        ret
      }
    }

    // http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.Stream
    def fibs: Stream[BigInt] = BigInt(0) #:: fibs.scanLeft(BigInt(1))(_ + _)

    def properDivisors(n: Long): Iterable[Long] = {
      var ret = collection.mutable.HashSet[Long](1L)
      val rec = (n: Long) => {
        if (n > 1) {
          for (i <- 2L until n / 2L) {
            if (n % i == 0) {
              ret.+=(i, n / i)
              properDivisors(i)
              properDivisors(n / i)
            }
          }
        }
      }

      rec(n)
      ret
    }

    /**
     * Stuff to do with testing/making prime numbers
     */
    object Primes {
      type NT = Long

      /**
       * Check if a number is prime by naively checking if its divisible by odd numbers less than its square root
       */
      def isPrimeNaive(n: NT): Boolean = {
        if (n == 2 || n == 3) true
        else if (n % 2 == 0) false
        else (3 until (Math.sqrt(n).toInt + 2) by 2) forall (n % _ != 0)
      }


      def _makePrimes(N: NT, isPrimeFunc: NT => Boolean): Seq[NT] = {
//        (for (i <- (3L until N by 2) if (isPrimeFunc(i))) yield i).+:(2L)
        (3L until N by 2).par.filter(isPrimeFunc(_)).+:(2L).toVector

      }

      def makePrimes(N: NT, isPrimeFunc: NT => Boolean): Seq[NT] = {
        val doIt = (n:NT) => _makePrimes(n, isPrimeFunc)
        val timedDoIt = Fun.TimeFunc1(doIt, (sec)=>println("Making %d primes took %f seconds ".format(N, sec)))
        timedDoIt(N)
      }

      /**
       * Generate a Seq of primes less than * N
       * by default do not use memoized version of isPrime
       */
      def makePrimes(N: NT): Seq[NT] = {
        makePrimes(N, isPrimeNaive)
      }

      // compute prime factors of a number N
      def primeFactors(N: NT): List[NT] = {
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

        _primeFactors(N, makePrimes(Math.sqrt(N).toInt + 2), Map())
      }
    }
  }

  // type for arguments of euler problem implementation.
  type A = Array[String]
  // type for return value of euler problem implementation.
  type R = Any

  // pretty print array
  implicit def arrayPrettyPrint[G](arg: Array[G]): String = {
    val vals = arg.foldLeft("") { (acc, n) =>
      {
        acc + n.toString + ", "
      }
    }
    "[%s]".format(vals)
  }

  implicit def seqPrettyPrint[G: ClassTag](arg: Seq[G]): String = {
    arrayPrettyPrint(arg.toArray[G])
  }

  //pretty print map
  implicit def mapPrettyPrint[K, V](m: Map[K, V]): String = {
    val vals = m.iterator.foldLeft("") { (acc, n) =>
      {
        acc + n._1 + ": " + n._2 + ", "
      }
    }
    "{%s}".format(vals)
  }

  /**
   * identity function to force scala to use implicit pretty print conversion
   */
  def pp(x: String): String = x

  def RunIt(func: A => R): (A => R) = {
    (args: A) =>
      {
        val ret = func(args);
        println("Solution: %s".format(ret));
        ret
      }
  }


  
  //////////// Actual problem implementations /////////////////

  def Problem_5(n: Long) = {
    var ps = List(1L)
    val merge = (x: List[Long], y: List[Long]) => {
      var ret = x
      for (i <- y.distinct) {
        val cntX = x.count(_ == i)
        val cntY = y.count(_ == i)
        var j = cntX
        while (j < cntY) {
          ret = i :: ret
          j = j + 1
        }
      }
      ret
    }
    (2L to n) foreach { (x) =>
      val pFactors = Fun.Primes.primeFactors(x)
      ps = merge(ps, pFactors)
    }
    println(pp(ps.sortWith(_ < _)))
    ps.foldLeft(1L)(_ * _)
  }

  def Problem_8(args: A) = {
    def multStr(a: String): Long = a.foldLeft(1L) { (acc, c) => acc * (c - '0') }
    val in = io.Source.fromInputStream(System.in).getLines.mkString
    val slide = in sliding (args(0).toInt)
    val num = slide max (new Ordering[String] { def compare(a: String, b: String) = multStr(a) compare multStr(b) })
    println("number %s".format(num))
    multStr(num)
  }

  def Problem_21(lim: Long) = {
    val d = Fun.mem1((n: Long) => Fun.properDivisors(n).sum)
    val isAmicable = (n: Long) => n == d(d(n)) && n != d(n)
    val nums = 1L until lim filter isAmicable
    println(nums)
    nums.sum
  }
  
  def Problem_50(lim: Long) = {
    val isPrime = Fun.Primes.isPrimeNaive _
    val primeList = Fun.Primes.makePrimes(lim, isPrime)

    def maxChain(i:Int, l:Seq[Long], exists: Long=>Boolean):(Long, Long) = {
      var maxChain = 0 
      var maxSum = 0L
      var sum = 0L
      for (j <- i until l.length) {
        val t = sum + l(j)
        if (t > lim) {
          return (maxChain, maxSum)
        }
        sum  = sum + l(j)
        if (exists(sum) && sum < lim) {
          maxChain = j - i + 1
          maxSum = sum
        }
      }
      (maxChain, maxSum)
    }
    Fun.TimeFunc0(()=>
    (0 until primeList.length/2).par.map((x)=>maxChain(x.toInt, primeList, isPrime)).maxBy(_._1))()

  }

  def MaxPathSum(args: A) = {
    var sums = (Map[Int, Int]().withDefaultValue(0), Map[Int, Int]().withDefaultValue(0))
    io.Source.fromInputStream(System.in).getLines foreach { (line) =>
      {
        (line.split(' ') map (_.toInt)).zipWithIndex foreach
          { (v) => val i = v._2; sums._2(i) = Math.max(sums._1(i), sums._1(i - 1)) + v._1 }
        sums = sums.swap
      }
    }
    sums._1.values.max
  }

  // Implicit conversions as helper methods for putting problems into map and dealing with String args
  object implicitDefs {
    implicit def intToString(i: Int): String = i.toString
    implicit def stringToLong(s: String) = s.toLong
    // magically chain implicits!  This line should chain conversion from string -> long -> int
    // http://stackoverflow.com/questions/5332801/how-can-i-chain-implicits-in-scala
    implicit def stringToInt[String <% Long](a: String): Int = a.toInt
    implicit def stringToBigInt[String <% Long](s: String): BigInt = BigInt(s.toString, 10)
    implicit def bigIntToString(s: BigInt) = s.toString
    implicit def arrayToLong(s: A): Long = stringToLong(s(0))
  }

  var problems = Map[String, A=>R]()

  def testProblem[E](func:Option[A=>R], arg:A, expected:E ) = {
    func match {
      case Some(f) => require(f(arg)==expected)
      case None => println("Ain't solved yet, cowboy")
    }
  }

  def testAll = {
    import implicitDefs._

    testProblem(problems get 1, Array(), 233168)
    testProblem(problems get 2, Array(4000000), 4613732)

    "All tests passed!"
  }

  def main(args: A) {
    // always play it safe
    val wrapIt = (RunIt _).compose(Fun.TimeFunc1(_: A => R, (x: Double) => println("Problem took %f seconds to solve".format(x))))

    import implicitDefs._

    problems put(1, (arg: A) => (for (i <- 1 until 1000 if i % 3 == 0 || i % 5 == 0) yield i).sum)
    problems put(2, (arg: A) => (for (i <- Fun.fibs takeWhile (_ < arg(0)) if i < arg(0) && i % 2 == 0) yield i).sum)
    problems put(3, (arg: A) => Fun.Primes.primeFactors(arg(0)).max)
    problems put(5, Problem_5(_))
    problems put(6, (arg: A) => Math.pow((1L to arg(0)).foldLeft(0L) { (acc, n) => acc + n}, 2L).toLong - (1L to arg(0)).foldLeft(0L) { (acc, n) => acc + n * n})
    // https://primes.utm.edu/howmany.html ;)
    problems put(7, (arg: A) => Fun.Primes.makePrimes(1000000)(10000))
    problems put(8, Problem_8 _)
    problems put(10, (arg: A) => Fun.Primes.makePrimes(arg(0)).sum)
    problems put(13, (arg: A) => io.Source.fromInputStream(System.in).getLines.foldLeft(BigInt("0", 10)) { (acc, c) => acc + BigInt(c, 10)}.subSequence(0, 10))
    problems put(16, (arg: A) => BigInt(2, 10).pow(arg(0)).toString.foldLeft(0) { (acc, n) => acc + n - '0'})
    problems put(18, MaxPathSum _)
    problems put(20, (arg: A) => (BigInt(1) until BigInt(arg(0))).foldLeft(BigInt(1))((acc, n) => acc * n).toString.foldLeft(0)((acc, n) => acc + n - '0'))
    problems put(21, Problem_21(_))
    problems put(25, (arg: A) => Fun.fibs.takeWhile((x) => x.toString.size < stringToLong(arg(0))).zipWithIndex.last._2 + 1)
    problems put(50, Problem_50(_))
    problems put(67, MaxPathSum _)
    problems put("primes", (arg: A) => Fun.Primes.makePrimes(arg(0)))
    problems put("primeFactors", Fun.Primes.primeFactors(_))
    problems put("properDivisors", (arg: A) => pp(Fun.properDivisors(arg(0)).toArray.sortWith(_ < _)))
    problems put("test", (arg:A) => testAll)

    // wrap each solution function with timing logic
    problems.keySet.foreach((k: String) => {
      problems get k match {
        case Some(func) => problems.put(k, wrapIt(func))
        case None => println("what")
      }
    })

    // execute the problem user selected
    var errMsg = "shit i didn't solve that one yet :/\n try %s".format(pp(problems.keySet.toArray.sortWith(_ < _)))
    if (args.length > 0) {
      problems get args(0) match {
        case Some(i) => i(args.tail)
        case None => println(errMsg)
      }
    } else println(errMsg)
  }
}
