class Solution {
public:
    string reorderSpaces(string text) {
        int space_count = 0;
        string result, word;
        vector<string> words;
        stringstream ss(text);
        while(ss>>word){
            words.push_back(word);
        }
        for(char ch:text){
            if(ch == ' '){
                space_count++;
            }
        }
        if(space_count == 0){
            return text;
        }
        int space_in_between = words.size() == 1 ? 0 : space_count / (words.size()-1);
        int end_space = words.size() == 1 ? space_count : space_count % (words.size()-1);
        for(int i = 0 ; i < words.size() ; i++){
            result += words[i];
            if( i != words.size() - 1){
                result += string(space_in_between, ' '); 
            }
        }
        result += string(end_space, ' '); 
        return result;
    }
};