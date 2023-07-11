class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        int tc = n * m;
        int count = 0;
        int startCol = 0;
        int endCol = m - 1;
        int startRow = 0;
        int endRow = n - 1;
        vector<int> ans;

        while (count < tc)
        {
            for (int i = startCol; i <= endCol && count < tc; i++)
            {
                ans.push_back(a[startRow][i]);
                count++;
            }
            startRow++;

            for (int i = startRow; i <= endRow && count < tc; i++)
            {
                ans.push_back(a[i][endCol]);
                count++;
            }

            endCol--;

            for (int i = endCol; i >= startCol && count < tc; i--)
            {
                ans.push_back(a[endRow][i]);
                count++;
            }
            endRow--;

            for (int i = endRow; i >= startRow && count < tc; i--)
            {
                ans.push_back(a[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans[k - 1];
    }
};




class Solution
{
public:
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        int tc = n * m;
        int count = 0;
        int startCol = 0;
        int endCol = m - 1;
        int startRow = 0;
        int endRow = n - 1;
        int temp = 0;

        while (count < tc)
        {
            for (int i = startCol; i <= endCol && count < tc; i++)
            {
                if (temp == k - 1)
                    return a[startRow][i];
                count++;
                temp++;
            }
            startRow++;

            for (int i = startRow; i <= endRow && count < tc; i++)
            {
                if (temp == k - 1)
                    return a[i][endCol];
                count++;
                temp++;
            }

            endCol--;

            for (int i = endCol; i >= startCol && count < tc; i--)
            {
                if (temp == k - 1)
                    return a[endRow][i];
                count++;
                temp++;
            }
            endRow--;

            for (int i = endRow; i >= startRow && count < tc; i--)
            {
                if (temp == k - 1)
                    return a[i][startCol];
                count++;
                temp++;
            }
            startCol++;
        }

        return -1; // Return a default value if kth element is not found
    }
};