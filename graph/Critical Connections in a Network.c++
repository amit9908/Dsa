class Solution {
public:
    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, vector<vector<int>>& ans, unordered_map<int, list<int>>& adjList) {
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr : adjList[src]) {
            if(nbr == parent) continue;
            if(!vis[nbr]) {
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                low[src] = min(low[src], low[nbr]);

                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            } else {
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adjList;

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
        int timer = 1;
        vector<int> tin(n, -1); // Initialize tin with -1
        vector<int> low(n, -1); // Initialize low with -1
        unordered_map<int, bool> vis;
        findBridges(0, -1, timer, tin, low, vis, ans, adjList);
        return ans;
    }
};