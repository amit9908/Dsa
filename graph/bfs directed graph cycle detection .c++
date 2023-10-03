class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> indegree(v, 0);
        int ans = 0;
        for (int i = 0; i < v; i++)
            for (auto it : adj[i])
                indegree[it]++;
    }
} queue<int> q;

for (int i = 0; i < v; i++)
    if (indegree[i] == 0)
        q.push(i);

while (!q.empty())
{
    int f = q.front();
    q.pop();
    ans++;
    for (auto it : adj[f])
        if (--indegree[it] == 0)
            q.push(it);
}
return ans != v;
}
}
;