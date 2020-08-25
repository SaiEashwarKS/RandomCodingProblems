class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
    
    #using dynamic programming
    
        tb = [] #dp table
                #i'th value denotes the minimum cost needed to travel upto and including i'th day
        for i in range(366):
            tb.append(0)
        days_index = 0
        for i in range(1, 366):
            if(days_index < len(days) and i == days[days_index]):
                tb[i] = 1
                days_index += 1
        #tb[1] = costs[0]
        #days_index = 1
        for i in range(1, days[-1] + 1):
            if (i < 1):
                return 9999999
            if (tb[i] == 0):
                tb[i] = tb[i-1]
            else:
                tb[i] = min(costs[0]+tb[i-1], costs[1]+tb[i-7], costs[2]+tb[30])
        return tb[days[-1]]
        
