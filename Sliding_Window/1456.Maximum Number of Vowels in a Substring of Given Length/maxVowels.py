class Solution:
    def maxVowels(self, s, k):
        ans = 0
        temp = 0
        for i in range(len(s)):
            if(s[i] in "aeiou"):
                temp += 1

            if(i >= k and s[i - k] in "aeiou"):
                temp -= 1
            
            ans = max(temp, ans)
        return ans
    
maxVowels = Solution()
assert maxVowels.maxVowels("abciiidef", 3) == 3, "ex1 failed"
assert maxVowels.maxVowels("aeiou", 2) == 2, "ex2 failed"
assert maxVowels.maxVowels("leetcode", 3) == 2, "ex3 failed"
print("all pass")