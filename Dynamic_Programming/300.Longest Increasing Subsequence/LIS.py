"""
to iteriate the original array and check the value to create the answer of array
ex: [4,10,4,3,8,9]
i = 0, ans [4]
i = 1, ans [4,10]  -> because 10 larger than ans[-1]
i = 2, ans [4,10]
i = 3, ans [3,10]  -> because 3 is the smallest one and we have to update it at ans[0]
i = 4, ans [3,8]   -> because 8 is larger than 3 and smaller than 10, so, we have to update it at ans[1]
i = 5, ans [3,8,9] -> because 9 is larger than 8, so, we have to append it at the end point 
"""
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ans = []
        ans.append(nums[0]) # because the nums of size is 1 at least 
        for i in range(1, len(nums)):
            if ans[-1] < nums[i]:
                ans.append(nums[i])
            else: # ans [4,10], num[i] = 3 
                # binary search 
                index = self.BinarySearch(nums[i], ans)
                ans[index] = nums[i]
                """
                # linear search
                for j in range(len(ans)):
                    if ans[j] >= nums[i]:
                        ans[j] = nums[i]
                        break;
                """
        return len(ans)
    def BinarySearch(self, num: int, ans: List[int]) -> int:
        # ans [2,4,7] num = 3; return index = 1
        #      L   R 
        left, right = 0, len(ans)
        while left < right:
            mid = (left + right) // 2
            if ans[mid] > num:
                right = mid
            elif ans[mid] < num:
                left = mid + 1
            else:
                left = mid
                break
        return left

LIS = Solution()
assert LIS.lengthOfLIS([10,9,2,5,3,7,101,18]) == 4, "ex1 failed"
assert LIS.lengthOfLIS([0,1,0,3,2,3]) == 4, "ex2 failed"
assert LIS.lengthOfLIS([4,10,4,3,8,9]) == 3, "ex3 failed"
print("all pass")