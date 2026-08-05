class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        edges = [[] for _ in range(n)]

        in_degree = [0]*n
        for u , v in invocations:
            edges[u].append(v)
            in_degree[v] += 1
        
        flag = [False]*n
        
        q = deque([k])
        flag[k] = True

        while q:
            u = q.popleft()

            for v in edges[u]:
                in_degree[v] -= 1

                if not flag[v]:
                    flag[v]= True
                    q.append(v)
        
        can_remove_all = True
        remaining = []

        for i in range(n):
            if flag[i] and in_degree[i] >0:
                can_remove_all = False
                break
            elif not flag[i]:
                remaining.append(i)

        if not can_remove_all:
            return list(range(n))
        
        return remaining
            
