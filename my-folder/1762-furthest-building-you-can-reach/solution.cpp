class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        vector<int> tmp(heights.size(),0);
        for(int i = 1 ; i < heights.size(); i++)
        {
            if(heights[i] > heights[i - 1])
            {
                tmp[i] = heights[i] - heights[i - 1];
            }
        }
        priority_queue<int>pq;
        long long int sum = 0;
        long long int ladderSum = 0;
        int ans = 0;
        for(int i = 1 ; i < tmp.size() ; i++)
        {
            if(tmp[i] > 0)
            {
                if(pq.size() < ladders)
                {
                    pq.push(-tmp[i]);
                    ladderSum += tmp[i];
                }
                else
                {
                    if(pq.size() == ladders && ladders != 0 && -pq.top() < tmp[i])
                    {
                        int no = pq.top();
                        pq.pop();
                        sum += -no;
                        pq.push(-tmp[i]);
                        ladderSum += tmp[i];
                    }
                    else 
                    {
                        sum += tmp[i];
                    }
                }
            }
            if(sum <= bricks)
                ans = i;
            else
                break;

        }
        return ans;
    }
};
