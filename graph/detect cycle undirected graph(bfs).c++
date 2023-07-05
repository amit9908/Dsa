#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    bool checkCycle(int src, std::unordered_map<int, bool>& visited, std::vector<int> adj[]) {
        std::queue<int> q;
        std::unordered_map<int, int> parent;
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (int neighbour : adj[front]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                    q.push(neighbour);
                } else if (neighbour != parent[front]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, std::vector<int> adj[]) {
        std::unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (checkCycle(i, visited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
};
