class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;
        auto partition = [&](int low,int high) -> int {
            int i = low - 1;
            int pivot = high;
            for(int j = low ; j < pivot; j++)
            {
                if(nums[j] <= nums[pivot])
                {
                    i++;
                    swap(nums[j],nums[i]);
                }
            }
            swap(nums[i + 1],nums[pivot]);
            return i + 1;
        };

        auto quick = [&](auto self,int low,int high)-> void {
            if(high <= low)
            {
                return;
            }
            int p = partition(low,high);
            self(self,low,p - 1);
            self(self,p + 1,high);

        };
        quick(quick,low,high);
    }
};
