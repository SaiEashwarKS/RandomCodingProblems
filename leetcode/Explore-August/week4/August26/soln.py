class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        res = [] #result list
        for i in range(1, n+1):
            if (i % 3 == 0 and i % 5 ==0): #multiple of both 3 and 5
                res.append("FizzBuzz")
            elif (i % 3 == 0):             #multiple of only 3
                res.append("Fizz")
            elif (i % 5 == 0):             #multiple of only 5
                res.append("Buzz")
            else :                         #not a multiple of either 3 or 5
                res.append(str(i))
        return res
        
