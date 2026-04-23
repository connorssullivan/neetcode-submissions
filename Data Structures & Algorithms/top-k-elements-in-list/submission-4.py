class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts={}
        for num in nums:
            counts[num] = counts.get(num, 0)+1

        sorCounts = sorted(counts.items(), key=lambda x: x[1], reverse=True)
        sol = []

        print(sorCounts)
        for i in range(k):
            sol.append(sorCounts[i][0])
        
        return sol

        
        
