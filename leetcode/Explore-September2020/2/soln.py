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
