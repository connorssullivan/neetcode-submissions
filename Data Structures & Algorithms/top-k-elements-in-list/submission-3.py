class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums_dict = {}
        for num in nums:
            nums_dict[num] = 1 +nums_dict.get(num, 0)
    
        found = []

        for i in range(k):
            most_freq = None
            for num in nums_dict:
                if num not in found and most_freq == None:
                    most_freq = num
                elif num in found and most_freq == None:
                    continue
                elif nums_dict[num] > nums_dict[most_freq] and num not in found:
                    most_freq = num
            if most_freq is not None:
                found.append(most_freq)
            

        return found            
        