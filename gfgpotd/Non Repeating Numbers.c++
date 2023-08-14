#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int> nums) {
        int allNumXor = 0;
        for (auto val : nums) {
            allNumXor ^= val;
        }

        int allNumXorRBit = allNumXor & -allNumXor;

        int x = 0;
        int y = 0;

        for (auto val : nums) {
            if ((allNumXorRBit & val) == 0) {
                x ^= val;
            } else {
                y ^= val;
            }
        }

        vector<int> ans;
        if(x <= y){
            ans.push_back(x);
             ans.push_back(y);
        }else{
             ans.push_back(y);
             ans.push_back(x);
        }
        return ans;

    }
};