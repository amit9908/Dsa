class Solution 
{
public:
    using ll = long long;

    void dfs(unordered_map<int, vector<int>>& g, vector<ll>& ans, vector<ll>& subTree, int u){
        int sub = 1;
        for (auto e : g[u]) {
            dfs(g, ans, subTree, e);
            ans[u] += (ll)subTree[e] * sub;
            sub += subTree[e];
        }
        subTree[u] = sub;
    }

    vector<long long> calcPairs(int n, vector<int>& p) {
        unordered_map<int, vector<int>> g;
        for (int i = 1; i < n; i++) {
            g[p[i]].push_back(i);
        }

        vector<ll> ans(n, 1);
        vector<ll> subTree(n, 0);

        dfs(g, ans, subTree, 0);
        return ans;
    }
};