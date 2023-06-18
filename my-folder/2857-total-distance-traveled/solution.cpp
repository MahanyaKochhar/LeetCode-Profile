class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int ans = 0;
        for(int i = 1 ; i <= mainTank ; i++)
        {
            ans = ans + 10;
            if(i % 5 == 0)
            {
                if(additionalTank > 0)
                {
                    additionalTank--;
                    mainTank++;
                }
            }
        }
        return ans;
    }
};
