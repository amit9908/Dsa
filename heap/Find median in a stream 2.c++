class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    void insertHeap(int &x)
    {
         if(maxheap.empty() and minheap.empty()){
             maxheap.push(x);
         }
         else {
             if(maxheap.size()>minheap.size()){
                 if(maxheap.top()>x){
                     minheap.push(maxheap.top());
                     maxheap.pop();
                     maxheap.push(x);
                 }
                 else {
                     minheap.push(x);
                 }
             }
             else 
             if(x<=maxheap.top()){
                 maxheap.push(x);
             }
             else {
                 minheap.push(x);
                 maxheap.push(minheap.top());
                 minheap.pop();
             }
         }
    }
    //Function to return Median.
    double getMedian()
    {
        if(maxheap.size()==minheap.size()) {
            return ((maxheap.top()+minheap.top())/2.0);
        }
        return maxheap.top();
    }


};



Time Complexity: If we omit the way how stream was read, complexity of median finding is O(N log N), as we need to read the stream, and due to heap insertions/deletions.

Auxiliary Space: O(N) At first glance the above code may look complex. If you read the code carefully, it is simple algorithm