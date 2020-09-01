class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        res = ""
        chars = [0, 0, 0, 0]
        B = [i for i in A]
        
        print(B)
        
        for i in B:
            if i < 3 and i > chars[0]:
                chars[0] = i
        if(chars[0] in B):
            B.remove(chars[0])
        else:
            return ""
        print(B)
        
        
        if(chars[0] == 2):
            for i in B:
                if i < 4 and i > chars[1]:
                    chars[1] = i
        else:
            chars[1] = max(B)
        if(chars[1] in B):
            B.remove(chars[1])
        print(B)
        
        for i in B:
            if i < 6 and i > chars[2]:
                chars[2] = i
        if(chars[2] in B):
            B.remove(chars[2])
        print(B)
        
        chars[3] = B[0]
        print(chars)
        
        
        if(len(B) > 1):
            if chars[0] == 2:
                print("In second loop")
                res = ""
                chars = [0, 0, 0, 0]
                B = [i for i in A]

                print(B)

                for i in B:
                    if i < 2 and i > chars[0]:
                        chars[0] = i
                if(chars[0] in B):
                    B.remove(chars[0])
                else:
                    return ""
                print(B)

                chars[1] = max(B)
                if(chars[1] in B):
                    B.remove(chars[1])
                print(B)

                for i in B:
                    if i < 6 and i > chars[2]:
                        chars[2] = i
                if(chars[2] in B):
                    B.remove(chars[2])
                else:
                    return ""
                print(B)
                
                chars[3] = B[0]
                print(chars)
            else:
                return ""
        
        
        
        res = str(chars[0]) + str(chars[1]) + ':' + str(chars[2]) + str(chars[3])
        print(res)
        
        return res
