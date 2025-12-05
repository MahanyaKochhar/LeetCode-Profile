class NumArray {
public:
    vector<int>pre;
    vector<int>nos;
    NumArray(vector<int>& nums)
    {
        pre.resize(nums.size() + 1);
        for(int i = 0 ; i < nums.size();i++)
        {
            nos.push_back(0);
        }
        for(int i = 1; i <= nums.size();i++)
        {
            update(i - 1,nums[i - 1]);
        }
    }
    
    void update(int index, int val)
    {
        index++;
        int tmp = val;
        val = val - nos[index - 1];
        nos[index - 1] = tmp;
        while(index < pre.size())
        {
            pre[index] += val;
            index += (index & -index);
        }
    }

    int findsum(int r)
    {
        int sum = 0;
        while(r > 0)
        {
            sum += (pre[r]);
            r -= (r & -r);
        }
        return sum;
    }
    
    int sumRange(int left, int right)
    {
        return findsum(right + 1) - findsum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
