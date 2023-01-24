class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord)
                return step;
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) // generate all possible string, by replacing every characters from a to z, and check if the generated string exist in out set or not, if exist update the step and push the {word, step+1} in queue
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};