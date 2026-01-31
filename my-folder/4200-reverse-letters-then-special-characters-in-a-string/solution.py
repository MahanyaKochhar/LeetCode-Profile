class Solution:
    def reverseByType(self, s: str) -> str:
        ans = ""
        org = ""
        sp = ""
        for ch in s:
           if ord(ch) >= 97 and ord(ch) <= 122:
               org += ch
           else:
               sp += ch

        rev_or = org[::-1]
        rev_sp = sp[::-1]
        i = 0 
        j = 0
        for ch in s:
            if ord(ch) >= 97 and ord(ch) <= 122:
                ans += rev_or[i]
                i += 1
            else:
                ans += rev_sp[j]
                j += 1
        return ans

                
