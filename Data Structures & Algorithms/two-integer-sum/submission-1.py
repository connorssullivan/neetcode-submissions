class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        sol = []
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i] + nums[j] == target:
                    sol.append(i)
                    sol.append(j)
                    return sol
        
        return sol
        