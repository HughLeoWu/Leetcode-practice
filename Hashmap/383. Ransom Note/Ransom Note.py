'''
  Make sure the magazing length is larger equal than ransomNote length
  we can store the magazing char in list and its counting.
  and then to iterate ransomNote, if it met the character in ransomNote and it also in the hashmap
  to decreace the counts and check if it larger than 0, otherwise it would be false
  ex: ransomNote = "aa", magazine = "ab"
  pool = [1,1,0,...0]
  pool = [-1,1,0,...0] -> -1 return false
'''
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        pool = [0] * 26
        for c in magazine:
            pool[ord(c) - ord("a")] += 1
        for c in ransomNote:
            pool[ord(c) - ord("a")] -= 1
            if pool[ord(c) - ord("a")] < 0:
                return False
        return True