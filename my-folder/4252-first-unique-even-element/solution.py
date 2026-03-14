class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        mp = {}
        for num in nums:
            if num % 2 == 0:
                mp[num] = mp.get(num,0) + 1

        for k,v in mp.items():
            if v == 1:
                return k
        return -1
