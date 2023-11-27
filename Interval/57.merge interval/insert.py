'''
we can append newInterval into intervals
to sort the intervals base on the first element
and then to implement the problem 56

time complexity O(nlogn)
space complexity O(1)
'''
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals = sorted(intervals) # intervals = [[1,3],[2,5],[6,9]]
        ans = []
        for idx in range(len(intervals)):  # idx = 0, 1, 2
            if len(ans) == 0 or ans[-1][1] < intervals[idx][0]:
                ans.append(intervals[idx])  # ans = [[1,3]] [[1,5],[6,9]] 
            else: # ans[0][1] = 3 > intervals[1][0]
                ans[-1][1] = max(ans[-1][1], intervals[idx][1]) # ans = [1,5]
        
        return ans