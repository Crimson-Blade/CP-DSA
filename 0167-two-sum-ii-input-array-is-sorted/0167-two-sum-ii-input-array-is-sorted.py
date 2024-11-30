class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        front, back = 0,len(numbers) -1
        while front <= back:
            if (numbers[front] + numbers[back]) == target:
                return [front + 1,back + 1]
            elif (numbers[front] + numbers[back]) > target:
                back -= 1
            else:
                front +=1
            