class Solution {
public:
    bool uniformArray(vector<int>& nums1)
    {
        auto construct = [&](int r) -> bool 
        {
            for(int i = 0 ; i < nums1.size(); i++)
            {
                int e = 0;
                if(nums1[i] % 2 == r)
                {
                    continue;
                }
                else
                {
                    for(int j = 0 ; j < nums1.size();j++)
                    {
                       if(j == i) 
                       {
                            continue;
                       }
                       else
                       {
                            if(((nums1[i] - nums1[j]) % 2 + 2) % 2 == r)
                            {
                                e = 1;
                                break;
                            }
                       }
                    }
                    if(e == 1)
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        };
        return construct(0) || construct(1);
    }
};
