class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    // unordered_map<string, bool> mt;   we cant include vector in unordered_map only map allow us 
    vector<vector<int>> ans;

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        string s = "";
        for (int j = 0; j < col; j++) {
            temp.push_back(M[i][j]);
            s += M[i][j] == 1 ? "1" : "0";
        }

        if (mt.find(s) == mt.end()) {
            ans.push_back(temp);
            mt[s] = true;
        }
    }

    return ans;
}
};

t.c 0(row*col);
s.c 0(row*col);