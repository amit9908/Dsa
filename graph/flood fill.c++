class Solution {
private:
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int, int>, bool>& vis, vector<vector<int>>& ans) {
        vis[{x, y}] = true;
        ans[x][y] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < ans.size() && newY >= 0 && newY < ans[0].size() && !vis[{newX, newY}] && ans[newX][newY] == oldColor) {
                dfs(newX, newY, oldColor, newColor, vis, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        map<pair<int, int>, bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr, sc, oldColor, newColor, vis, ans);
        return ans;
    }
};
