class Solution {
    func longestMonotonicSubarray(_ nums: [Int]) -> Int {
        
        var l = 0
        var r = 0
        var res = 1

        while r + 1 < nums.count {
            r += 1

            guard nums[r] != nums[r - 1] else {
                l = r
                continue
            }

            guard (nums[l] < nums[l + 1]) == (nums[r - 1] < nums[r]) else {
                l = r - 1
                continue
            }

            res = max(res, r - l + 1)
        }

        return res
    }
}