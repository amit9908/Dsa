class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        long long mini = INT_MAX;
        long long i = 0, j = 0;
        long long sum = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            while (sum >= target)
            {
                mini = min(mini, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if (mini == INT_MAX)
            return 0;
        return mini;
    }
};

// t.c 0(n)
// s.c 0(1)