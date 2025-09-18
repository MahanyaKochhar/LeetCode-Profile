function maxKDistinct(nums: number[], k: number): number[]
{
    nums.sort((num1,num2) => num2 - num1);
    const st = new Set()
    const ans : number[] = []
    for(const element of nums)
    {
        if(st.size < k && !st.has(element))
        {
            ans.push(element)
        }
        st.add(element)
    }
    return ans
};
