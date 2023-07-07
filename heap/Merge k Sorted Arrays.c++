class Info {
public:
    int value;
    int row;
    int col;
    
    Info(int val, int r, int c) {
        value = val;
        row = r;
        col = c;
    }
};

class Compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->value > b->value;
    }
};

class Solution {
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        priority_queue<Info*, vector<Info*>, Compare> minHeap;
        
        for (int i = 0; i < K; i++) {
            Info* temp = new Info(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        vector<int> ans;
        
        while (!minHeap.empty()) {
            Info* temp = minHeap.top();
            int topEle = temp->value;
            int topRow = temp->row;
            int topCol = temp->col;
            minHeap.pop();
            ans.push_back(topEle);
            
            if (topCol + 1 < arr[topRow].size()) {
                Info* newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
                minHeap.push(newInfo);
            }
        }
        
        return ans;
    }
};
// t.c nlogk