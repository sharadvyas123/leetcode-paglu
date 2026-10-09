class Solution:
    def minInsertions(self, s: str) -> int:
        res = 0
        right = 0

        for c in s:
            if c == '(':
                right += 2
                if right %2 == 1:
                    # that means we have stand alone ) 
                    res += 1
                    right -= 1
            else: # )
                right -= 1
                if right < 0: # means we need to add one ( 
                    res += 1
                    right += 2 # no
                
        return right + res