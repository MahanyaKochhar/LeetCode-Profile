class Solution {
public:
    int minAllOneMultiple(int k)
    {
        set<int>seen;
        int no = 1;
        int dig = 1;
        while(true)
        {
            if(seen.contains(no % k))
            {
                return -1;
            }
            
            if(no % k == 0)
            {
                break;
            }
            else
            {
                seen.insert(no % k);
                no = (no % k) * 10 + 1;
                dig++;
            }
        }
        return dig;
    }
};
