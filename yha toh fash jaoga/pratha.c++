#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> cR, int np, int sol)
{
    int currP = 0;
    // int pos = s[0];

    for (int i = 0; i < cR.size(); i++)
    {
        int R = cR[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + j * R <= sol)
            {
                ++currP;
                timeTaken += j * R;
                ++j;
            }
            else
            {
                break;
            }
        }

        if (currP >= np)
        {
            return true;
        }
    }

    return false;
}

int minTimeComplete(vector<int> cR, int np)
{
    int start = 0;
    int highestRanker = *max_element(cR.begin(), cR.end());
    int end = highestRanker * (np * (np + 1) / 2);
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(cR, np, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int nP, nC;
        cin >> nP >> nC;
        vector<int> cooksRanks;
        while (nC--)
        {
            int R;
            cin >> R;
            cooksRanks.push_back(R);
        }
        cout << minTimeComplete(cooksRanks, nP) << endl;
    }

    return 0;
}