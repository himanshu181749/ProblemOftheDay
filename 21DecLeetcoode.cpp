// class Solution {

//     bool isBipartite(int src, vector<int>adj[], int colour[]){

//         queue<int>q;
//         colour[src]=1;
//         q.push(src);

//         while(!q.empty()){
//             int node=q.front();
//             q.pop();

//             for(auto v : adj[node]){
//                 if(colour[v]==-1){
//                     colour[v]=1-colour[node];
//                     q.push(v);
//                 }
//                 else if(colour[v]==colour[node])return false;
//             }

//         }
//         return true;
//     }

// public:
//     bool possibleBipartition(int nodes, vector<vector<int>>& dislikes) {
//         vector<int>adj[nodes+1];

//         for(int i=0; i<dislikes.size(); i++){
//             int n1=dislikes[i][0];
//             int n2=dislikes[i][2];


//             adj[n1-1].push_back(n2-1);
//             adj[n2-1].push_back(n1-1);

//         }

//         int colour[nodes];
//         memset(colour, -1, sizeof(colour));

//         for(int i=0; i<nodes; i++){
//             if(colour[i]==-1){
//                 return isBipartite(i,adj, colour);
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // Check for bipartite graph can be done using 2-color graph coloring.
        // Idea is to use two colors and assign colors to each node such that
        // each adjacent node gets a different color, if we this assignment is not
        // possible, then it is not bipartite
        
        // create the graph
        vector<vector<int>> g(N);
        for(auto &edge: dislikes) {
            g[edge[0] - 1].emplace_back(edge[1] - 1);
            g[edge[1] - 1].emplace_back(edge[0] - 1);
        }
        // for keeping track of color of each node
        // -1: unvisited
        // 0: color 1
        // 1: color 2
        vector<int> color(N, -1);
        // in case of disconnected graph
        for(int i = 0; i < N; i++) {
            // take the current as root node
            if(color[i] == -1) {
                // color it 
                color[i] = 1;
                queue<int> q;
                q.emplace(i);
                
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    // color the adjacent nodes
                    for(int adj = 0; adj < g[curr].size(); adj++) {
                        int adj_idx = g[curr][adj];
                        if(color[adj_idx] == -1) {
                            // color it to mark visited
                            color[adj_idx] = 1 - color[curr];
                            q.emplace(adj_idx);
                        }
                        else if(color[adj_idx] == color[curr])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
