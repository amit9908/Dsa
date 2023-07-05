class Solution {
private:
    bool topoSort(int V, unordered_map<int, list<int>>& adj)
    {
        vector<int> res;
        unordered_map<int, int> indegree;
        queue<int> q;

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

            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        if (res.size() == V) {
            return true;
        } else {
            return false;
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        for (auto task : prerequisites) {
            int u = task[0]; // Use task[0] instead of prerequisites[0]
            int v = task[1]; // Use task[1] instead of prerequisites[1]
            adjList[v].push_back(u); // Add a semicolon at the end of the line
        }

        bool ans = topoSort(numCourses, adjList);
        return ans; // Add a return statement
    }
};
