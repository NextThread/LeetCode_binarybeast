class Solution {
public:
    string predictPartyVictory(string senate) {
        int count = 0, len = 0;
        // When the length of senate doesn't decrease, the game is over.
        while (senate.size() != len) {
            string s;
            len = senate.size();
            for (int i = 0; i < len; i++) {
                if (senate[i] == 'R') {
                    if (count++ >= 0) s += 'R';
                }
                else if (senate[i] == 'D') {
                    if (count-- <= 0) s += 'D';
                }
            }  
            swap(s, senate);
        }
        if (senate[0] == 'R') 
            return "Radiant";
        else 
            return "Dire";
    }
};