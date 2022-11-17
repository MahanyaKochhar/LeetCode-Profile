/**
 * @param {number[]} nums
 * @return {number}
 */
var distinctAverages = function(nums)
{
    nums.sort(function(a,b){return a-b});
    const s=new Set();
    let l=0,r=nums.length-1;
    while(l<r)
    {
        let v=(nums[l]+nums[r])/2;
        s.add(v);
        l++;
        r--;
    }
    return s.size;
};
