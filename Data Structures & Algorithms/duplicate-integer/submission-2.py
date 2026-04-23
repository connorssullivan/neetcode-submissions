class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        counts = {}
        for num in nums: 
            counts[num] = counts.get(num, 0) + 1
        
        for num, value in counts.items(): 
            if value > 1:
                return True
            
        return False

         