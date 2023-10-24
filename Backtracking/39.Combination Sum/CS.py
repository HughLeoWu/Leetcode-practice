class Solution:
    def combinationSum(self, candidates, target):
        ans = []
        temp = []
        self.backtrack(candidates, target, ans, temp, 0)
        return ans

    def backtrack(self, candidates, target, ans, temp, index):
        if target < 0:
            return
        elif target == 0:
            ans.append(list(temp))
        else:
            for i in range(index, len(candidates)):
                temp.append(candidates[i])
                self.backtrack(candidates, target - candidates[i], ans, temp, i)
                temp.pop()

CS = Solution()
assert CS.combinationSum([2,3,6,7], 7) == [[2,2,3], [7]], "ex1 failed"
assert CS.combinationSum([2,3,5], 8) == [[2,2,2,2],[2,3,3],[3,5]], "ex2 failed"
assert CS.combinationSum([2], 1) == [], "ex3 failed"
print("all pass")