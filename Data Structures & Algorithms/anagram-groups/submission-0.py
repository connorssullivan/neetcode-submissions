class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_count_dict = {}
        for s in strs:
            sorted_str = ''.join(sorted(s))
            if sorted_str in word_count_dict:
                word_count_dict[sorted_str].append(s)
            else:
                word_count_dict[sorted_str] = [s]

        anser = []
        for i in word_count_dict.values():
            anser.append(i)
        return anser
        