#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n)
{
    // str is character array and n is the length of the character array
    sort(str, str + n);
    int index = 0;
    int i = 0;
    while (i < n - 1)
    {
        if (str[i] != str[i + 1])
        {
            str[index++] = str[i];
        }
        else
        {
            i++;
        }
    }
    return str;
}

int main()
{
    char str[7] = {'a', 'b', 'a', 'c', 'd', 'n', 'd'};
    removeDuplicate(str, 7);
    cout << str << endl;
}

public:
int start = 0, end = 0, maxi = INT_MIN;
int solve(string &s, int i, int j, vector<vector<int>> dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
    {
        int remLen = j - i - 1;
        if (remLen == solve(s, i + 1, j - 1, dp))
        {
            if (remLen > maxi)
            {
                maxi = remLen;
                start = i;
                end = j;
            }
            return dp[i][j] = 2 + remLen;
        }
    }

    return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
}

int solve(string S, int ii, int jj, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[ii][jj] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[j])
            {
                int remLen = j - i - 1;
                if (remLen == solve(s, i + 1, j - 1, dp))
                {
                    if (remLen > maxi)
                    {
                        maxi = remLen;
                        start = i;
                        end = j;
                    }
                    dp[i][j] = 2 + remLen;
                }
            }

            dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
        }
    }
}

string longestPalin(string S)
{
    // code here
    int n = S.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int i = 0;
    string ans = "";
    int count = solve(S, i, n - 1, n);
    for (int i = start; i <= end; i++)
    {
        ans += S[i];
    }
    return ans;
}
}
;