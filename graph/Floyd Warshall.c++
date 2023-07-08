//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
        // Code here
        int n = matrix.size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
            }
        }


        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                     matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        // for negative weight cycle
        
       // for(int i = 0;i<n;i++)
       // {
       //     if(matrix[i][i] < 0)
       //     {
       //         cout<<"Negative Cycle Present"<<endl;
       //     }
       // }
        
        
       for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
        
    }
};








The time complexity of the provided code is O(n^3), where n represents the size of the input matrix.

The code contains three nested loops, with each loop iterating n times. Therefore, the overall time complexity is O(n * n * n), which simplifies to O(n^3).

The first two nested loops initialize any cell in the matrix that contains -1 with a large value (1e9), assuming it represents an unreachable distance.

The next set of nested loops performs the Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices in the graph represented by the matrix. This algorithm has a time complexity of O(n^3).

Finally, there is a loop that replaces all occurrences of 1e9 in the matrix with -1, indicating that those cells represent unreachable distances.

Overall, the time complexity of the code is O(n^3). Space complexity 0(1).