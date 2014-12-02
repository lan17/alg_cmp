object Main {
    def main(args: Array[String]) {
        println(mult(args(0).toInt, args(1).toInt))
    }

    def mult(x:Int, y:Int):Int = {
        if (x == 1) y else y + mult(x -1, y)
    }
}

