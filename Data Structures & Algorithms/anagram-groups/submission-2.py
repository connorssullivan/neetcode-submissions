class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        output=defaultdict(list)
        for s in strs:
            key=tuple(sorted(s))
            output[key].append(s)
        
        return list(output.values())


        