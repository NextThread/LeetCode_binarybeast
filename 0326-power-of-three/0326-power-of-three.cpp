class Solution {
public:
    bool isPowerOfThree(int n) {
	return n > 0 && 1162261467 % n == 0;
	// pow(3, floor(log(INT_MAX)/log(3))) = 1162261467 
}
};