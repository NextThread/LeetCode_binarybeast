class Solution {
public:
    void find_all(int n,string &curr,vector<string> &v)
{
	if(curr.size()==n)
	{
		v.push_back(curr);
		return ;
	}
	for(char i='a';i<='c';i++)
	{
		if(curr.size()==0||i!=curr.back())
		{
			curr.push_back(i);
			find_all(n,curr,v);
			curr.pop_back();
		}
	}
}
string getHappyString(int n, int k) {
	vector<string> v;
	string curr;
	find_all(n,curr,v);
	sort(v.begin(),v.end());
	if(k>v.size())
		return "";
	return v[k-1];
}
};