class Solution {
public:
    bool completePrime(int num)
    {
        vector<int>digits;
        while(num != 0)
        {
            digits.push_back(num % 10);
            num = num / 10;
        }
        int cnt = 0;
        int curr = 0;

        auto checkPrime = [](int no) -> bool 
        {
            if(no == 1)
            {
                return false;
            }
            for(int i = 2; (i * i) <= no ; i++)
            {
                if(no % i == 0)
                {
                    return false;
                }
            }
            return true;
        };
        
        for(int i = 0 ; i < digits.size();i++)
        {
            curr = curr + digits[i] * pow(10,cnt);
            cnt++;
            if(!checkPrime(curr))
            {
                return false;
            }
        }
        cout << "\n";
        curr = 0;
        cnt = 0;
        for(int i = digits.size() - 1; i >= 0 ; i--)
        {
            curr = curr * 10 + digits[i];
            if(!checkPrime(curr))
            {
                return false;
            }
        }

        return true;
    }
};
