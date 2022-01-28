class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxLength=0;
	vector<char>temp;
	for(int i=0;i<s.size();i++)
	{
		if(find(temp.begin(),temp.end(),s[i])==temp.end())
		{
			temp.push_back(s[i]);
		}
		else
		{
			maxLength=max(maxLength,(int)temp.size());
			vector<char>::iterator it=find(temp.begin(),temp.end(),s[i]);
			temp.erase(temp.begin(),it+1);
			temp.push_back(s[i]);
		}
	}
	maxLength=max(maxLength,(int)temp.size());
	return maxLength;
    }
};
