class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for (const auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(n , false);
        int complete_components = 0;

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int v_count = 0;
                int e_count = 0;

                queue<int>q;
                q.push(i);
                visited[i]= true;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    v_count++;
                    e_count += adj[curr].size();

                    for(int neighbour : adj[curr]){
                        if(!visited[neighbour]){
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }

                e_count /= 2;
                
                // condition 
                if(e_count == (v_count * (v_count -1)) /2){
                    complete_components++;
                }
            }
        }

        return complete_components;
    }
};