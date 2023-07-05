void buildtree(int &i , int min ,int max,vector<int>& A){
    if(i>=A.size()) return;
    
    if(A[i] > min && A[i] < max){
        int rootData = A[i++];
        buildtree(i , min , rootData , A);
        buildtree(i , rootData , max , A);
    }
}

int Solution::solve(vector<int> &A) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;
    buildtree(i , min ,max , A);
    return i==A.size();
}