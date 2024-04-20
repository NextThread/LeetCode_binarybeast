object Solution {
     def findFarmland(land: Array[Array[Int]]): Array[Array[Int]] = {

    type int = Int
    type ai  = Array[int]
    import scala.collection.mutable.ArrayBuffer
    val ab = new ArrayBuffer[ai]
    val m  = land.length
    val n  = land(0).length
    for (i <- 0 until m; j <- 0 until n; if (land(i)(j) == 1)) {
      var l = j + 1
      while (l < n && land(i)(l) == 1) l += 1
      var d = i + 1
      while (d < m && land(d)(j) == 1) d += 1
      ab.append(Array(i, j, d - 1, l - 1))
      for (x <- i until d; y <- j until l) land(x)(y) = 0
    }

    ab.toArray
  }
}