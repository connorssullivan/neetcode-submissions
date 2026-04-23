class Solution:
    def isPalindrome(self, s: str) -> bool:

        newList = []

        for i in s:
            if i.isalpha() or i.isdigit():
                newList.append(i.lower())
        
        for i in range(len(newList)):
            if newList[i] != newList[len(newList)-1-i]:
                return False
        
        return True

        