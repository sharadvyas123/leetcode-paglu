from collections import deque
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # building the adj metrics 

        adj = [[] for _ in range(n)]

        for u , v in edges :
            adj[u].append(v)
            adj[v].append(u)
            # cause undirected edges
        
        visited = [False]*n
        complete_components = 0

        for i in range(n):
            if not visited[i]:
                # we perform the traversal (DFS)
                v_count = 0
                e_count = 0
                
                queue =deque([i])
                visited[i] = True

                while queue:
                    curr = queue.popleft()
                    v_count += 1
                    e_count += len(adj[curr])
                    for neighbour in adj[curr]:
                        if not visited[neighbour]:
                            queue.append(neighbour)
                            visited[neighbour] = True
                
                # devide by 2 cause we encounter same edge twice
                e_count //= 2

                # main condifiton E = V*(V-1) / 2

                if e_count ==( v_count * (v_count -1) )// 2:
                    complete_components +=1
        
        return complete_components
