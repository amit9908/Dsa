class Solution
{
public:
    bool checkBound(vector<vector<int>> &grid, vector<pair<int, int>> &v)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (auto pt : v)
        {
            if (pt.first < 0 || pt.first >= n || pt.second < 0 || pt.second >= m)
            {
                return false;
            }
        }
        return true;
    }

    bool getAllVertices(vector<vector<int>> &grid, vector<pair<int, int>> &v, pair<int, int> c, int delta)
    {
        pair<int, int> A(c.first - delta, c.second);
        pair<int, int> B(c.first, c.second + delta);
        pair<int, int> C(c.first + delta, c.second);
        pair<int, int> D(c.first, c.second - delta);

        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;

        return checkBound(grid, v);
    }

    void getAllSum(vector<vector<int>> &grid, int i, int j, priority_queue<int> &pq)
    {
        pq.push(grid[i][j]);
        int delta = 1;
        vector<pair<int, int>> v(4);
        while (getAllVertices(grid, v, {i, j}, delta))
        {
            pair<int, int> &A = v[0];
            pair<int, int> &B = v[1];
            pair<int, int> &C = v[2];
            pair<int, int> &D = v[3];
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

            for (int k = 1; k < (B.first - A.first); k++)
            {
                csum += grid[A.first + k][A.second + k];
            }

            for (int k = 1; k < (C.first - B.first); k++)
            {
                csum += grid[B.first + k][B.second - k];
            }

            for (int k = 1; k < (C.first - D.first); k++)
            {
                csum += grid[C.first - k][C.second - k];
            }

            for (int k = 1; k < (D.first - A.first); k++)
            {
                csum += grid[D.first - k][D.second + k];
            }
            pq.push(csum);
            delta++;
        }
    }

    bool canPush(vector<int> &ans, int top)
    {
        for (auto val : ans)
        {
            if (val == top)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        vector<int> ans;
        priority_queue<int> pq;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                getAllSum(grid, i, j, pq);
            }
        }

        while (!pq.empty() && ans.size() < 3)
        {
            int top = pq.top();
            pq.pop();
            if (canPush(ans, top))
            {
                ans.push_back(top);
            }
        }
        return ans;
    }
};