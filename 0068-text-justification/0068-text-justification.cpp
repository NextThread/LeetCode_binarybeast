class Solution {
private:
    /** 
     * Returns string containing left-aligned line formed using words[low..high]
     * @param maxWidth: Total length of the line
     */
    string getLeftAlignedLine(int low, int high, vector<string>& words, int maxWidth) {
        string line;
        for(int i = low; i <= high; i++)
            line += words[i] + " ";
        line.pop_back();
        line += string(maxWidth - line.size(), ' ');
        return line;
    }
    
    /**
     * Returns string containing justified line formed using words[low..high]
     * @param extraSpace: Number of extra spaces that need to be spread evenly between
     *      the words. This count doesn't include the single spaces that already need
     *      to be inserted between each pair of words.
     */
    string getJustifiedLine(int low, int high, vector<string>& words, int extraSpaces) {
        string line;
        int n = high - low + 1, slots = n - 1;
        
        // The number of extra spaces that must be inserted between every pair of words.
        // Some pairs might have (space+1) spaces between them if the total is in excess.
        int space = slots > 0 ? extraSpaces / slots : -1;        

        for(int i = 0; i < n - 1; i++) {
            line += words[low + i] + " " + string(space, ' ');
            slots--;
            extraSpaces -= space;
            
            // Greedily add an extra space after the current word if the remaining
            // spaces are still in excess.
            if(extraSpaces > slots * space) {
                line += " ";
                extraSpaces--;
            }
        }
        line += words[high] + string(extraSpaces, ' ');
        return line;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            int currWidth = 0;
            int j = i;
            while(j < words.size() && (currWidth + words[j].size()) <= maxWidth)
                currWidth += words[j++].size() + 1;
            j < words.size()
                ? res.push_back(getJustifiedLine(i, j - 1, words, maxWidth - currWidth + 1))
                : res.push_back(getLeftAlignedLine(i, j - 1, words, maxWidth));
            i = j - 1;
        }
        return res;
    }
};