
// brute force , jo khudse socha hai :)
class Solution {
    #define pii pair<int, int>
    int DistSum(int n, vector<vector<int>>& edges, vector<int> adj[], int src){
        vector<int>dist(n, INT_MAX);
        priority_queue<pii , vector<pii>, greater<pii>>minh;

        dist[src]=0;
        minh.push({0,src});
        while(!minh.empty()){
            auto p=minh.top();
            minh.pop();

            for(auto v: adj[p.second]){
                if(dist[v]>1+p.first){
                    dist[v]=(1+p.first);
                    minh.push({dist[v], v});
                }
            }
        }
        return accumulate(dist.begin(), dist.end(), 0);
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            ans[i]+=DistSum(n, edges, adj, i);
        }

        return ans;
    }
};  

// optimised approach jo ki copy kiya hai smjh v nhi aaya thoda  :)

class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
        
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};
