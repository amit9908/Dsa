//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        int m=0;
        int i=0;
        int j=n-1;
        
        while(m<=j){
            if(arr[m] == 0){
                swap(arr[m], arr[i]);
                m++;
                i++;
            }else{
                swap(arr[m] , arr[j]);
                j--;
            }
        }
    }
};