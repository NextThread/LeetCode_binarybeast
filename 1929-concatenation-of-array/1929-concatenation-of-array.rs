impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let v = nums.clone(); // copied the prev one into the new vector
        [nums,v].concat() // add the new vector to the old one
    }
}