class Solution
{
public:
    int solve(int n, vector<int> &days, vector<int> &costs, int ind, vector<int> &dp)
    {

        // BASE CASE agar index N ya usse bda hojae to hum sare days travel kr chuke h return krjao
        if (ind >= n)
        {
            return 0;
        }

        // step3 dp
        if (dp[ind] != -1)
            return dp[ind];

        // Mere pass 3 option honge har bar ya to ma ek day ka pass lu ya
        // 3 din ka pass lu ya fir 7 din ka pass lu

        // 1 din ka pass

        int option1 = costs[0] + solve(n, days, costs, ind + 1, dp);

        // ek option ha ma 7 din ka pass lelu lekin agar mne 7 din ka pass lelia to mera
        //  index muje jb tk agge le jane hoga jb tk 7 din nhi ho jate
        // yani agar mne pass lia h day 1 pe to abb 1 se 7 tk jitne bhi din h unke lia call nhi krunga ma

        int i;
        // iss for loop ko hmne bas i increase krne ke lia chlaya h

        for (i = ind; i < n && days[i] < days[ind] + 7; i++)
            
        int option2 = costs[1] + solve(n, days, costs, i, dp);

        // abb ind na pass krke i pass krenge kyuki i hmara 7 days ke
        // lia traverse kr chuka h or same for 30 days

        int j;
        for (j = ind; j < n && days[j] < days[ind] + 30; j++)
            
        int option3 = costs[2] + solve(n, days, costs, j, dp);

        // step 2 dp
        return dp[ind] = min(option1, min(option2, option3));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        // step 1 dp
        vector<int> dp(n + 1, -1);
        int ans = solve(n, days, costs, 0, dp);
        return ans;
    }
};