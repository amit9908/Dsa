class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        int sum2 = 0;
        for (auto it : nums)
            sum2 += it;
        return sum - sum2;
    }
};

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int missingnum = 0, cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                missingnum = i;
                cnt = 1;
                break;
            }
        }

        if (cnt == 1)
        {
            return missingnum;
        }
        else
        {
            return n;
        }
    }
};