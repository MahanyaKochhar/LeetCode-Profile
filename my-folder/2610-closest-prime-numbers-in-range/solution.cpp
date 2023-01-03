class Solution {
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool>isPrime(1000001,true);
        isPrime[1]=false;
        for(int j=2;j*j<=right;j+=1)
        {
            if(isPrime[j]==true)
            {
                for(int k=j*j;k<=right;k+=j)
                {
                    isPrime[k]=false;
                }
            }
            
        }
        vector<int>ans;
        for(int i=left;i<=right;i++)
        {
            if(isPrime[i]==true)
                ans.push_back(i);
            // if(ans.size()==2)
            //     break;
                
        }
        vector<int>fin{-1,-1};
        if(ans.size()<2)
            return fin;
        // else
        //     return ans;
        int mini=1e7;
        for(int j=1;j<ans.size();j++)
        {
            if(ans[j]-ans[j-1]<mini)
            {
                fin[0]=ans[j-1];
                fin[1]=ans[j];
                mini=ans[j]-ans[j-1];
            }
        }
        return fin;
    }
};
