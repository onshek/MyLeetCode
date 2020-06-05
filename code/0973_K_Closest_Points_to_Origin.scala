object Solution {
    def kClosest(points: Array[Array[Int]], K: Int): Array[Array[Int]] = {
        val res = points.sortBy(p => scala.math.pow(p(0),2) + scala.math.pow(p(1),2))
        return res.slice(0, K)
    }
}