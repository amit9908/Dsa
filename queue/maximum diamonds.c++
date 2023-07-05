long long maxDiamonds(int A[], int N, int K) {
        // code here
        long long ans=0;
        priority_queue<int>pq;
        for(int i=0;i<N;i++)
        pq.push(A[i]);
        while(K--){
            int diamond=pq.top();
            pq.pop();
            ans+=diamond;
            pq.push(diamond/2);
        }
        return ans;
    }