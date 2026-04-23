class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for num in range(len(nums)-1):
            start = num+1
            for start in range(num+1, len(nums)): 
                if nums[start] == nums[num]:
                    return True
        
        return False


         