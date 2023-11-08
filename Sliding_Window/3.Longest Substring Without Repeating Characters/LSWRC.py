'''
first, we define the right and left index and forward the right string, 
       and then to put in the hashmap when you met the char.  
second, when you meet the duplicate character, to move the left of index 
ex:
p w w k e p  seen {} -> dictionary "hashmap"
r = right index
l = left index
when r = 2, s[r] = "w" already in the seen {}, so we will update the left to the index left = 2
full flow:  
    r = 0 seen {p = 0}, ans = max(ans, right - left + 1) = 1
    r = 1 seen {p = 0; w = 1} ans = 2
    r = 2 seen {p = 0; w = 1} because s[r] in the seen, so we have to move forward the left index to 3
        left = seen[w] + 1 = 2; seen {p = 0; w = 2} 
    r = 3 seen {p = 0; w = 2; k = 3} ans = 0, 
    r = 4 seen {p = 0; w = 2; k = 3; e = 4} ans = 4 - 2 + 1 = 3
    r = 5 seen[p] < left, ans = 5 - 2 + 1 = 4 and the final seen {p = 5; w = 2; k = 3; e = 4}
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, ans = 0, 0
        seen = {}
        for right in range(len(s)):
            if s[right] not in seen or seen[s[right]] < left:
                ans = max(ans, right - left + 1)
            else: 
                left = seen[s[right]] + 1
            seen[s[right]] = right
        return ans
    
LSWRC = Solution()
assert LSWRC.lengthOfLongestSubstring("abcabcbb") == 3, "ex1 failed"
assert LSWRC.lengthOfLongestSubstring("bbbbb") == 1, "ex2 failed"
assert LSWRC.lengthOfLongestSubstring("pwwkew") == 3, "ex3 failed"
print("all pass")