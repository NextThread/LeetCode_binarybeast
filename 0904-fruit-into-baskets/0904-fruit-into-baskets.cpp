class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       // we need to maintain a sliding window, whenver our no of unique
      // elements will become > 2, we need to restart the window from there
      map<int, int> mp;
      int slow = 0, fast = 0;
      for(fast = 0 ; fast < fruits.size() ; fast++)
      {
        mp[fruits[fast]]++;
        if(mp.size() > 2) // size exceeded of 2
        {
          if(--mp[fruits[slow]] == 0) mp.erase(fruits[slow]);
          slow++;
        }
      }
      return fast-slow;
    }
};