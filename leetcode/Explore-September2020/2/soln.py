class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        l = list(s)
        if(len(l) < 2):
            return False
        i = 2
        
        while(len(l)//i > 0):
            if(l[0:len(l)//i ] * i == l):
                return True
            i += 1
        return False

   
"""
Saw a cleaner solution :
Explanation:
After looking at the top submission, I found these and thought I explain how they work:
If there is a repition in s, it means s can be seen as a combination of (at least) two string t.
s = t + t
If we double s, we get "t + t + t + t = 4t". cutting away the first and last letter, we end with " u + t + t + u = u + s + u" with u being whatever is left (could be empty).
But because s is at least 2t, 2s is 4t and taking away the first and last letter only "destroys" 2t, so the string still contains s.


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
      return s in (s + s)[1: -1]
"""
