object Main {
  def main(args: Array[String]) {
    val bar = fibClosure() 
    for (i <- 0 until 10) {
      println(bar())
    }
    println("---")
    val op = (a:Int, b:Int) => {
      println("%d - %d".format(a,b))
      a + b
    }
    def fibs: Stream[Int] = 0 #:: fibs.scanLeft(1)(op)
    for (i <- fibs take 15) {
      println(i)
    }
  }

  val fibClosure = () => {
    var a = 1
    var b = 0
    () => {
      val j = a + b
      a = b
      b = j
      j
    }
  }
  
  val fibGenerator = () => {
    var a = 1
    var b = 0
    while(true) {
      val ret = a + b
      a = b
      b = ret
      //yield (ret)
      
    }
  }
}
