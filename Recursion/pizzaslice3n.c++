class Solution {
public:

    int solve(vector<int>& slices , int s , int e , int n){
        if(n == 0 || s>e) return 0;
        int include = slices[s] + solve(slices , s+2 , e , n-1);
        int exclude = 0 + solve(slices , s+1 , e , n);

        return max(include , exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int pizzaSize = slices.size();
        int n = pizzaSize/3;
        
        int opt1 = solve(slices , 0 , pizzaSize-2 , n);
        int opt2 = solve(slices , 1 , pizzaSize-1 , n);

        return max(opt1,opt2);
    }
};