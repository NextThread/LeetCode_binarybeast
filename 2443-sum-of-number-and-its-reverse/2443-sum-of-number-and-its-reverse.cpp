class Solution {
public:
  
    int reverse(int n)
    {
      int rev = 0;
      while(n)
      {
        rev = rev*10+n%10;
        n /= 10;
      }
      return rev;
    }
  
    bool sumOfNumberAndReverse(int num) {
      if(num == 0) return true;
        for(int i = 1 ; i <= num ; i++)
        {
          if(i + reverse(i) == num) return true;
        }
      return false;
    }
};