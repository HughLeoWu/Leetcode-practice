/* n = 4, k = 2
 for 1 - 4
    backtrack(id + 1)
    temp = [], [1,2] if temp.size() == k, ans.push_back(temp) return, pop_back
    temp =     [1,3]
    [1] code stack (2)
    [1,2] code stack (3) -> return
          code stack (3) -> temp.pop_back [1], 
    [1,3] code stack (4) -> return 
          code stack (4) -> temp.pop_back [1],
    [1,4] code stack (5) -> return
          code stack (2) -> temp.pop_back [] 
    [2] code stack (3) ... 
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(1, n, k, ans, temp);
        return ans;
    }
    void backtrack(int start, int n, int k, vector<vector<int>>& ans, vector<int>& temp) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for(int idx = start; idx <= n; idx++) {
            temp.push_back(idx);
            backtrack(idx + 1, n, k, ans, temp);
            temp.pop_back();
        }
    }
};