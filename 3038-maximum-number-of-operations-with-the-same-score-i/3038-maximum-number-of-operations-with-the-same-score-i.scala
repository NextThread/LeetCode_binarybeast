object Solution {
  def maxOperations(nums: Array[Int]): Int = {
    val sum = nums.take(2).sum
    if(nums.size % 2 == 0) nums.drop(2).sliding(2, 2).map(_.sum).takeWhile(_ == sum).size + 1
    else nums.drop(2).init.sliding(2, 2).map(_.sum).takeWhile(_ == sum).size + 1
  }
}