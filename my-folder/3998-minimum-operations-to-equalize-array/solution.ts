function minOperations(nums: number[]): number
{
    const s = new Set()
    for(let i = 0; i < nums.length; i++)    
    {
        s.add(nums[i])
    }
    return s.size > 1 ? 1 : 0
};
