class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;

        for(int i=0 ; i<piles.size() ; i++){
            maxHeap.push(piles[i]);
        }
        
        while(k--){
            int top = maxHeap.top();
            maxHeap.pop();
            top = top - floor(top/2);
            maxHeap.push(top);
        }

        int sum = 0;
        while(!maxHeap.empty()){
            int top = maxHeap.top();
            maxHeap.pop();
            sum += top;
        }

        return sum;
        
    }
};

// t.c o(n + klogn)