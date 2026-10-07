class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def isValid(s):
            count = 0
            for c in s:
                if c == '(':
                     count += 1
                elif c == ")":
                    count -= 1
                    if count < 0:
                        return False
            
            return count == 0
        
        q = {s}
        
        while q:
            valid = list(filter(isValid , q))
            if valid :
                return valid
            
            next_q = set()

            for symbol in q :
                for i in range(len(symbol)):
                    if symbol[i] in "()":
                        next_q.add(symbol[:i] + symbol[i + 1:])
            q = next_q
        

        return [""]