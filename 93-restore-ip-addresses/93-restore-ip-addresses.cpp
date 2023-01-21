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
                        if(i+j+k+l == s.length()) // if we have 4 substring that is equal string length
                        {
                            int part1 = stoi(s.substr(0, i)); // convert the 4 substring into integers to check if they are in range
                            int part2 = stoi(s.substr(i, j));
                            int part3 = stoi(s.substr(i+j, k));
                            int part4 = stoi(s.substr(i+j+k, l));
                            if(part1 <= 255 and part2 <= 255 and part3 <= 255 and part4 <= 255) // if all the parts are in range 
                            {
                                string ip = to_string(part1)+"."+to_string(part2)+"."+to_string(part3)+"."+to_string(part4); // convert this into an IP
                                if(ip.length() == s.length()+3) // +3 is for extra "." dots that we have inserted inside the IP
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