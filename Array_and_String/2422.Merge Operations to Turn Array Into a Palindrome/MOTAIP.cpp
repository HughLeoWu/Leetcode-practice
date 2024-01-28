/*
according the palindrome feature, 
ex: [a, x, b, c] -> if 'c' is not equal to 'a', it can plus 'b' and check the result will be equal to 'a' or not
                    because the array's constraint is postive integer, if c is smaller than a, and then plus b could probably be equal to a, 
                    if not we need to compare again.   
ex: [4,3,2,1,2,3,2] -> it would be: s = start index, e = end index
 s           e 
[4,3,2,1,2,3,2]
[4,3,2,1,2,3,2]
l/s       r/e    l = 4, r = 5
   s       e     l = 7, r = 5
   s     e       l = 7, r = 7
     s e         l = 2, r = 1 
[7,2,1,2,5]
[7,2,1,7]
[7,3,7] -> 4
[4,7,2,1,7,5,2]
     s e 
time complexity = O(n)
space complexity = O(1)
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        long left = nums[s], right = nums[e];
        int ans = 0;
        while(s < e) {
            if(left > right) {
                right += nums[e - 1];
                e--;
                ans++;
            } else if(left < right) {
                left += nums[s + 1];
                s++;
                ans++;
            } else {
                s++;
                e--;
                left = nums[s];
                right = nums[e];
            }
        }
        return ans;
    }
};