class Solution {
public:
    int strStr(string haystack, string needle) {
     return haystack.find(needle);
        // int lo = 0;
        // while(lo < haystack.size())
        // {
        //     if(haystack[lo] == needle[0])
        //     {
        //         bool gotit = true;
        //         int temp = 0, sec = lo;
        //         while(temp < needle.size())
        //         {
        //             if(needle[temp] != haystack[sec]) return -1;
        //             else{
        //                 temp++;
        //                 sec++;
        //             }
        //         }
        //         if(temp == needle.size()) return lo;
        //     }
        // }
        // return -1;
    }
};