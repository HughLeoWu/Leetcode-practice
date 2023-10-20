/*
# str1 = "abc" str2 = "ad" 
# two pointer (i, j)
#        "a"          "a" -> (i, j) += 1
#        "b" can be "b" or "c", but str2 = "d", it can't mapping this character, so to only move forward str1 i +=1
#        "c": "c" or "d"  -> (i, j) += 1
# so if j equal to the length of str2, it means that it can make subsequence from str1.
# one more thing: 
# because in the ASCII of lower case letter, we can map to "a, b, c, ... z" -> 0, 1, 2, ..., 25
# if char = 'z', it means that this character would be on '25', we can substract '25'
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()) {
            if(str1[i] == str2[j] || str1[i] - 25 == str2[j] || str1[i] + 1 == str2[j])
                j++;
            i++; 
        }
        return j == str2.size();
    }
};

int main()
{
    Solution CMS;
    // example 1 
    cout << CMS.canMakeSubsequence("abc", "ad") << endl; // 1
    // example 2
    cout << CMS.canMakeSubsequence("zc", "ad") << endl; // 1
    // example 3
    cout << CMS.canMakeSubsequence("ab", "d") << endl;  // 0
    return 0;
}