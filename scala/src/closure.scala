object Main {
  def main(args: Array[String]) {
    val bar = foo() 
    for (i <- 0 until 10) {
      println(bar())
    }
    println(fib(10))
  }

  val foo = () => {
    var a = 1
    var b = 0
    () => {
      val j = a + b
      a = b
      b = j
      j
    }
  }

  val fib = (y:Int) => {
    val f = foo()
    for (i <- 0 until y) {
      f()
    }
    f()
  }

}
