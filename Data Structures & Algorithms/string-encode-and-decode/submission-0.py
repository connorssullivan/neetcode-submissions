class Solution:

    def encode(self, strs: List[str]) -> str:
        single_string = ''
        for s in strs:
            single_string += str(len(s)) + '#' + s 
        
        return single_string
        

    def decode(self, s: str) -> List[str]:
        sol, i = [], 0

        while i < len(s):
            j = i
            while s[j] != '#':
                j+=1
            length = int(s[i:j])
            sol.append(s[j+1 : j + length + 1])
            i = j + length + 1
        
        return sol
