class Solution {
public:
    int halveArray(vector<int>& nums)
    {
        priority_queue<double>pq;
        double sum;
        for(int i=0;i<nums.size();i++)
        {
        	sum+=nums[i];
        	pq.push(nums[i]);
        }
        double req=sum/2;
        double curr_red=0;
        int op=0;
        while(true)
        {
        	if(curr_red>=req)
        		break;
        	double top=pq.top();
        	pq.pop();
        	curr_red+=top/2;
        	pq.push(top/2);
        	op++;
        }
        return op;
    }
};
