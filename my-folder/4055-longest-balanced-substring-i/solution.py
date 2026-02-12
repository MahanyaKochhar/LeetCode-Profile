class Solution:
    def longestBalanced(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            fq = [0 for i in range(26)]
            for j in range(i,len(s)):
                p = ord(s[j]) - ord('a')
                fq[p] += 1
                prev = -1
                e = 0
                for k in range(26):
                    if fq[k] != 0:
                        if fq[k] == prev or prev == -1:
                            prev = fq[k]
                        else:
                            e = 1
                            break
                fin = j - i + 1 if e == 0 else -1
                ans = max(fin,ans)
        return ans
