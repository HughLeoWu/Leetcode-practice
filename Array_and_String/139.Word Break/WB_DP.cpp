/*
ex: catsandog => dp [t,f,f,f,f,f,f,f,f,f]
(i, j) (0,0) -> (0,2) s.substr(j, 3) = cat in wordDict => dp[3] = true
(4,0) cats in wordDict -> dp[4] = true; (7,0) catsand -> dp[4] = true => (7,4) and
and in wordDict dp[7] = true; (i,j) (9,0) false, (9,3); (9,4); (9,7) false return dp[9]
init dp [t,f,f,f,f,f,f,f,f,f]
end  dp [t,f,f,t,t,f,f,t,f,f] -> return the latest value 
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        unordered_set<string> worddict;
        for(int i = 0; i < wordDict.size(); i++)
            worddict.insert(wordDict[i]);    
        dp[0] = true;
        for(int i = 0; i < s.length() + 1; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] == true) {
                    string sub_str = s.substr(j, i - j); // (3, 0) sub_str = cat; (4,0) cats 
                    if(worddict.find(sub_str) != worddict.end())
                        dp[i] = true;                    // dp[3] = true; dp[4] = true
                }
            }
        }
        return dp[s.length()];
    }
};

int main()
{
    Solution WB;
    vector<string> wordDict = {"leet","code"};
    cout << WB.wordBreak("leetcode", wordDict) << endl; // 1
    vector<string> wordDict1 = {"cats","dog","sand","and","cat"};
    cout << WB.wordBreak("catsandog", wordDict1) << endl; // 0
    vector<string> wordDict2 = {"apple","pen"};
    cout << WB.wordBreak("applepenapple", wordDict2) << endl; // 1
    return 0;
}