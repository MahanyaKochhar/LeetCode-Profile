class Solution {
public:
    int minimumPartition(string s, int k)
    {
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]-'0'>k)
                return -1;
        }
        long long int curr=s[0]-'0';
        int ans=0;
        for(int i=1;i<s.length();i++)
        {
            if(curr*10+s[i]-'0'>k)
            {
                if(curr>k)
                {
                    return -1;
                }
                curr=s[i]-'0';
                ans++;
            }
            else
            {
                curr=curr*10+s[i]-'0';
            }
        }
        if(curr<=k)
            ans++;
        else
            return -1;
        return ans;
    }
};
