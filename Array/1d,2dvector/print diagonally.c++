class Solution{
	
	public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
	    vector<int> ans;
		for(int j=0;j<N;j++){
		    int i=0, k=j;
		    while(i<N && k>=0){
		        ans.push_back(A[i][k]);
		        i++, k--;
		    }
		}
		for(int i=1;i<N;i++){
		    int j=N-1, k=i;
		    while(k<N){
		        ans.push_back(A[k][j]);
		        k++, j--;
		    }
		}
		return ans;
	}

};