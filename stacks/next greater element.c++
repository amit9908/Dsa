#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> ans(n, -1);
        s.push(-1);
        
        for (int i = n - 1; i >= 0; i--)
        {

            
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            
            // Check if the stack is not empty before accessing the top element.
            if (!s.empty())
            {
                ans[i] = s.top();
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};

//for next smaller element
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> ans(n, -1);
        s.push(-1);
        
        for (int i = n - 1; i >= 0; i--)
        {

            
            while (!s.empty() && s.top() >= arr[i])
            {
                s.pop();
            }
            
            // Check if the stack is not empty before accessing the top element.
            if (!s.empty())
            {
                ans[i] = s.top();
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};

//previous smaller element
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> ans(n, -1);
        s.push(-1);
        
        for (int i = 0;  i < n; i++)
        {

            
            while (!s.empty() && s.top() >= arr[i])
            {
                s.pop();
            }
            
            // Check if the stack is not empty before accessing the top element.
            if (!s.empty())
            {
                ans[i] = s.top();
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};