class Solution {
public:
    int countLargestGroup(int n)
    {
        vector<int>fq(100,0);
        for(int i = 1 ; i <= n ; i++)
        {
            int no = i;
            int sum = 0;
            while(no != 0)
            {
                int dig = no % 10;
                sum += dig;
                no = no / 10;
            }
            fq[sum]++;
        }
        int maxCnt = 0,currMax = -1;
        for(int i = 0 ; i < fq.size();i++)
        {
            if(fq[i] > currMax)
            {
                currMax = fq[i];
                maxCnt = 1;
            }
            else if(fq[i] == currMax)
            {
                maxCnt++;
            }
        }
        return maxCnt;
    }
};
