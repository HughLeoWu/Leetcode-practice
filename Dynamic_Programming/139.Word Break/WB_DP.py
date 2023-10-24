class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(len(s) + 1):
            for j in range(0, i):
                if dp[j] == True:
                    substr = s[j:i]
                    if substr in wordDict:
                        dp[i] = True
        return dp[len(s)]

WB = Solution()
assert WB.wordBreak("leetcode", ["leet","code"]) == True, "ex1 failed"
assert WB.wordBreak("applepenapple", ["apple","pen"]) == True, "ex2 failed"
assert WB.wordBreak("catsandog", ["cats","dog","sand","and","cat"]) == False, "ex3 failed"
print("all pass")