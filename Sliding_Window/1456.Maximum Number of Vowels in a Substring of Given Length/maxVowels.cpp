/*
    to use the k size of sliding window to iteriate this string.
    and then, to count the vowel character, if the new character is vowel, it should be add 1, 
    on the other hand, if the latest character in the sliding window is vowel, it should be decrease 1  
    ex: s = a b c i i i d e f k = 3, the sliding window = k
        sl  1,2,3                    sl[1] = 'a' ans = 1
        sl    2 3 4                  sl[4] = 'i', ans += 1 but we have to reduce 1, cause sl[1] = 'a' ans -= 1
                3 4 5                sl[5] = 'i', ans += 1 -> the temp value is 2, so, it needs to update the answer to 2
                  4 5 6              sl[5] = 'i', ans += 1 -> the temp value is 2, so, it needs to update the answer to 3     
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size();
        int ans = 0, temp = 0;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        for(int idx = 0; idx < size; idx++) {
            if(vowel.find(s[idx]) != vowel.end()) { // abciiidef
                temp++;  // 2
            }
            if(idx >= k && vowel.find(s[idx - k]) != vowel.end()) { // "b" 
                temp--; 
            }
            ans = max(ans, temp); // ans 1, 2
            if(ans == k) return ans;
        }
        return ans;
    }
};

int main() {
    Solution maxVowels;
    cout << maxVowels.maxVowels("abciiidef", 3) << endl; // The substring "iii" contains 3 vowel letters.
    cout << maxVowels.maxVowels("aeiou", 2) << endl;     // Any substring of length 2 contains 2 vowels 
    cout << maxVowels.maxVowels("leetcode", 3) << endl;  // "lee", "eet" and "ode" contain 2 vowels.
    return 0;
}