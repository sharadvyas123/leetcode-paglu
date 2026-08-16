class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        cnt = [0,0,0]
        for s in stones:
            cnt[s%3] += 1

        c0 , c1 , c2 = cnt
        
        if c0% 2 == 0:
            # both Taken so nothing chnges !
            return c1 >= 1 and c2 >= 1

        return abs(c1 -  c2) > 2