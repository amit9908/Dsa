class node{
    public:
     int data;
     int row;
     int col;

     node(int d , int r , int c){
         data = d;
         row = r;
         col = c;
     }
};

class compare{
    public:
    bool operator()(node* a , node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int  mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node* , vector<node*> , compare> mHeap;
        int k = nums.size();

        for(int i=0 ; i<k ; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini , element);
            mHeap.push(new node(element , i , 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!mHeap.empty()){
            node* top = mHeap.top();
            int topEle = top->data;
            int topRow = top->row;
            int topCol = top->col;
            mHeap.pop();

            mini = topEle;

            if(maxi - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxi;
            }

            if(topCol + 1 < nums[topRow].size()){
                maxi = max(maxi , nums[topRow][topCol+1]);
                node* newNode = new node(nums[topRow][topCol+1] , topRow , topCol+1);
                mHeap.push(newNode);
            }else{
                break;
            }

            
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};

//the overall time complexity of the code is O(k * log(k) + n * log(k)), which can be simplified to O(n * log(k)) as k is typically smaller than n.