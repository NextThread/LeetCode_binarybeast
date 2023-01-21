class Solution {
public:
    
    vector<string> restoreIpAddresses(string s) {
       vector<string> res;
        string cur;
        for(int i = 1 ; i <= 3 ; i++)
        {
            for(int j = 1 ; j <= 3 ; j++)
            {
                for(int k = 1 ; k <= 3 ; k++)
                {
                    for(int l = 1 ; l <= 3 ; l++)
                    {
                        if(i+j+k+l == s.length())
                        {
                            int part1 = stoi(s.substr(0, i));
                            int part2 = stoi(s.substr(i, j));
                            int part3 = stoi(s.substr(i+j, k));
                            int part4 = stoi(s.substr(i+j+k, l));
                            if(part1 <= 255 and part2 <= 255 and part3 <= 255 and part4 <= 255)
                            {
                                string ip = to_string(part1)+"."+to_string(part2)+"."+to_string(part3)+"."+to_string(part4);
                                if(ip.length() == s.length()+3)
                                {
                                    res.push_back(ip);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};