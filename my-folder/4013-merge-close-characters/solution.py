class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        while True:
            i, j = -1 , -1
            for m in range(len(s)):
                for n in range(m + 1, len(s)):
                    if s[m] == s[n] and n - m <= k:
                        j = n
                        break
                    if j != -1:
                        break
            if j == -1:
                break
            else:
                tmp = ""
                for m in range(len(s)):
                    if m == j:
                        continue
                    else:
                        tmp += s[m]
                s = tmp
        return s
                
