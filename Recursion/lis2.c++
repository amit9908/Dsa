#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int *nums,int n , int k, int prev, int currIdx)
{
    if (currIdx == n)
        return 0;

    int include = 0;
    if (nums[currIdx] > nums[prev] && nums[currIdx] - nums[prev] <= k)
        include = 1 + longestIncreasingSubsequence(nums, n , k, currIdx, currIdx + 1);

    int exclude = longestIncreasingSubsequence(nums,  n ,k, prev, currIdx + 1);

    return max(include, exclude);
}

 int main(){

    int nums[] = {7,4,5,1,8,12,4,7};
    int k=5;
    int n = 8;
    int ans =longestIncreasingSubsequence(nums, n , k, -1, 0);
     cout << ans <<  endl;
 }
