class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        time = [(target - position[i])/speed[i] for i in range(n)]
        
        
        comb = list(zip(position,time))
        sorted_position, ordered_time = zip(*sorted(comb, key = lambda x:x[0]))
        ordered_time_list = list(ordered_time)
        
        maxele  = ordered_time_list[-1]
        output = 1
        
        for num in ordered_time_list[::-1]:
            if num > maxele:
                maxele = num
                output +=1
        return output