class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num == 2:
                ans.append(-1)
            else:
                for j in range(1,num):
                    res = j | j + 1
                    if res == num:
                        ans.append(j)
                        break
        return ans
