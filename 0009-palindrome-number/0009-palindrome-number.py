class Solution:
    def isPalindrome(self, x: int) -> bool:
        Y = str(x)
        if (Y[::-1]==str(x)):
            return True
        else:
            return False
       