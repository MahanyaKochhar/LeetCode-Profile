class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums)
    {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            int pro=nums[i];
            while(pro%2==0)
            {
                s.insert(2);
                pro=pro/2;
            }

            for(int l=3;(l*l)<=pro;l+=2)
            {
                while(pro%l==0)
                {
                    pro=pro/l;
                    s.insert(l);
                }

            }
            if(pro>1)
                s.insert(pro);
    }
        return s.size();
    }
};
