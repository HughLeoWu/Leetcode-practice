# str1 = "abc" str2 = "ad" 
# two pointer (i, j)
#        "a"          "a" -> (i, j) += 1
#        "b" can be "b" or "c", but str2 = "d", it can't mapping this character, so move forward str1 only i +=1
#        "c": "c" or "d"  -> (i, j) += 1
# so if j equal to the length of str2, it means that it can make subsequence from str1.
# one more thing: 
# because in the ASCII of lower case letter, we can map to "a, b, c, ... z" -> 0, 1, 2, ..., 25
# if char = 'z', it means that this character would be on '25', we can substract '25'

class Solution:
    def canMakeSubsequence(self, s1: str, s2: str) -> bool:
        if len(s2) > len(s1): 
            return False
        i, j = 0, 0
        while i < len(s1) and j < len(s2):
            if s2[j] in [s1[i], chr(ord(s1[i]) - 25), chr(ord(s1[i]) + 1)]:
                j += 1
            i += 1
        return j == len(s2)

CMS = Solution()
# example 1 str1 = "abc", str2 = "ad"
assert CMS.canMakeSubsequence("abc", "ad") == True, "ex1 failed"
# example 2 str1 = "zc", str2 = "ad"
assert CMS.canMakeSubsequence("zc", "ad") == True, "ex2 failed"
# example 3 str1 = "ab", str2 = "d"
assert CMS.canMakeSubsequence("ab", "d") == False, "ex3 failed"
print("all pass")