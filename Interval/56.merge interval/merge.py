class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        ans = []
        for interval in intervals:
            if len(ans) is 0:
                ans.append(list(interval))
            else:
                if ans[-1][1] >= interval[0]:
                    ans[-1][1] = max(ans[-1][1], interval[1])
                else:
                    ans.append(list(interval))
        return ans

Merge = Solution()
assert Merge.merge([[1,3],[2,6],[8,10],[15,18]]) == [[1,6],[8,10],[15,18]], "ex1 failed"
assert Merge.merge([[1,4],[4,5]]) == [[1,5]], "ex2 failed"
assert Merge.merge([[1,5], [1,4],[1,2]]) == [[1,5]], "ex3 failed"
print("all pass")