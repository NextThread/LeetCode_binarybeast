class Solution {
    func sumOfTheDigitsOfHarshadNumber(_ x: Int) -> Int {
        let divisor = (x/100 + (x%100)/10 + x%10)
        return x % divisor == 0 ? divisor : -1
    }
}