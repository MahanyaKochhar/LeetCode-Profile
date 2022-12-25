class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex)
    {
        int mini=INT_MAX;
        int curr_idx2=startIndex;
        int curr_idx=startIndex;
        int cnt=0,cnt2=0;
        do
        {
            if(words[curr_idx]==target)
            {
                mini=min(mini,cnt);
            }
            cnt++;
            curr_idx=(curr_idx+1)%words.size();
        }while(curr_idx!=startIndex);
        do
        {
            if(words[curr_idx2]==target)
            {
                mini=min(mini,cnt2);
            }
            cnt2++;
            curr_idx2=(curr_idx2-1+words.size())%words.size();
        }while(curr_idx2!=startIndex);
        if(mini!=INT_MAX)
                return mini;
        else
            return -1;
        
    }
};
