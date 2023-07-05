class Solution {
private:
    void toposort(int V, unordered_map<int, list<int>>& adj, vector<int>& res) {
        queue<int> q;
        unordered_map<int, int> indegree;

        for (int i = 0; i < V; i++) {
            for (auto nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            res.push_back(front);

            for (auto nbr : adj[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if (res.size() != V) {
            res.clear(); // Clear the result vector to indicate the presence of a cycle.
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> res;
        for (auto nbr : prerequisites) {
            int u = nbr[0];
            int v = nbr[1];
            adj[v].push_back(u);
        }
        toposort(numCourses, adj, res);
        return res;
    }
};