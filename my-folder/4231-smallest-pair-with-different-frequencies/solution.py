class Solution:
    def minDistinctFreqPair(self, nums: list[int]) -> list[int]:
        fq = {}
        for num in nums:
            fq[num] = (fq[num] + 1) if num in fq else 1

        nums.sort()
        for i in range((len(nums))):
            for j in range(i + 1,len(nums)):
                if nums[i] < nums[j] and fq[nums[i]] != fq[nums[j]]:
                    return [nums[i],nums[j]]

        return [-1,-1]
            
        
