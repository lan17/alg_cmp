object Main {
  object Fun {
    // http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.Stream
    def fibs: Stream[BigInt] = BigInt(0) #:: fibs.scanLeft(BigInt(1))(_ + _)
  }

  def TimeFunc[A,R](func:A=>R)   = {
    (args:A) =>
      {
        val start = System.nanoTime
        val ret = func.apply(args)
        println("Problem took %f seconds to solve".format((System.nanoTime - start)/1e9))
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

  def main(args: Array[String]) {
    val problems = collection.mutable.Map[Int, Array[String] => Any]()
    problems += 1 -> Problem_1 _
    problems += 2 -> Problem_2 _
   
    // wrap each solution function with timing logic
    problems.keySet.foreach((k:Int) => {
      problems get k match {
        case Some(func) => problems.put(k, TimeFunc(func))
        case None => println("what")
      }
    })

    problems get args(0).toInt match {
      case Some(i) => println("Solution: " + i(args.tail).toString)
      case None => println("shit i didn't solve that one yet :/")
    }
  }
}