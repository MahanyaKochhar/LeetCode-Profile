class Solution:
    def minOperations(self, nums: List[int], target: List[int]) -> int:
        flag = 0 if nums[0] == target[0] else 1
        ans = 0 if nums[0] == target[0] else 1
        mp = {}
        mp[nums[0]] = ans
        for i in range(1,len(nums)):
            if nums[i] == nums[i - 1]:
                if nums[i] != target[i]:
                    if flag == 0 and mp[nums[i]] == 0:
                        ans += 1
                        flag = 1
                        mp[nums[i]] = 1
            else:
                flag = 0
                if nums[i] not in mp:
                    mp[nums[i]] = 0
                if nums[i] != target[i]:
                    if flag == 0 and mp[nums[i]] == 0:
                        ans += 1
                        flag = 1
                        mp[nums[i]] = 1

        return ans
