class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            if num == 2:
                ans.append(-1)
            else:
                for j in (range(32)):
                    if num & (1 << j):
                        continue
                    else:
                        ans.append(num - (1 << (j - 1)))
                        break
        return ans
