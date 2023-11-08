/*
  Make sure the magazing length is larger equal than ransomNote length
  we can store the magazing char in hashmap and its counting.
  and then to iterate ransomNote, if it met the character in ransomNote and it also in the hashmap
  to decreace the counts and check if it larger than 0, otherwise it would be false
  ex: ransomNote = "aa", magazine = "ab"
  pool = {"a" = 1, "b" = 1}
  pool = {"a" = -1, "b" = 1} -> return false
*/
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> pool;
        for(auto c: magazine) {
            pool[c]++; 
        }
        for(auto c: ransomNote) {
            if(pool.find(c) == pool.end())
                return false;
            else
                if(--pool[c] < 0)
                    return false;
                  
        }
        return true;
    }
};