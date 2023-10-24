/*
backtracking
candidates = [2,3,6,7] target = 7
            2
        2      3 ...
    2; 3 = 7 bingo append to answer, 6, 7 return           
2 = 8 return, 3, 6, 7, return  
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates, target, temp, ans, 0);
        return ans;
    }
    void backtrack(vector<int>& cand, int target, vector<int>& temp, vector<vector<int>> &ans, int index) {
        if(target < 0)
            return;
        else if(target == 0) {
            ans.push_back(temp); // ans = [2,2,3]
        } else {
            for(int i = index; i < cand.size(); i++) { // i = 0; 0; ...; 0, 1
                temp.push_back(cand[i]);               
                // temp [2]; [2,2]; ...; [2,2,2,2]; [2,2,2,3]; ... [2,2,3]
                backtrack(cand, target - cand[i], temp, ans, i);
                temp.pop_back();                
                // temp [2,2,2]; [2,2,2]; ... [2,2]
            }
        }
    }
};