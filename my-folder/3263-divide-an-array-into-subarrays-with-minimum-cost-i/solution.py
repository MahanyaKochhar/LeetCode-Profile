class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0]
        tmp = []
        for i in range(1,len(nums)):
            tmp.append(nums[i])
        tmp.sort()
        ans += (tmp[0] + tmp[1])
        return ans
