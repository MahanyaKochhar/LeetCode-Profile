class Solution {
public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;
        for(int i = low ; i <= high ; i++)
        {
            vector<int>digits;
            int no = i;
            while(no != 0)
            {
                digits.push_back(no % 10);
                no = no / 10;
            }
            if(digits.size() % 2 == 0)
            {
                int lsum = 0, rsum = 0;
                for(int j = 0 ; j < digits.size() ; j++)
                {
                    if(j < digits.size() / 2)
                    {
                        lsum += digits[j];
                    }
                    else
                    {
                        rsum += digits[j];
                    }
                }
                if(lsum == rsum)
                    cnt++;
            }
        }
        return cnt;
    }
};
