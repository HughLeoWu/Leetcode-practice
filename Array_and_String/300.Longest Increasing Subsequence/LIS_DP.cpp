/*
to use dynamic programming to solve this problem directly.
if(nums[i] > nums[j]) 
   dp[i] = max(dp[i], dp[j] + 1)
it means that we need to increase 1 while it larger than the pervious element. 
ex: 
    nums [10,9,2,5,3,7,101,4]
    dp   [ 1,1,1,1,1,1,1,1] -> idx = 3 nums[3] = 5 > nums[2] -> dp[3] = max(dp[3], dp[2] + 1) = 2
    dp   [ 1,1,1,2,1,1,1,1] -> idx = 4 nums[4] = 3 > nums[2] -> dp[4] = max(dp[4], dp[2] + 1) = 2
    dp   [ 1,1,1,2,2,1,1,1] -> idx = 5 nums[5] = 7 > nums[2] -> dp[5] = max(dp[5], dp[2] + 1) = 2 
    dp   [ 1,1,1,2,2,3,1,1] ...                                         max(2, dp[3] + 1)) = 3
    dp   [ 1,1,1,2,2,3,4,3]  
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for(int j = 1; j < nums.size(); j++) {
            for(int i = 0; i < j; i++) {
                if(nums[j] > nums[i]) 
                    dp[j] = max(dp[j], dp[i] + 1);
                    ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};