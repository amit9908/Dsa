#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{5, 3, 4, 8, 2, 8};
    int n = arr.size();

    for (int round = 1; round < n; round++)
    {
        int val = arr[round];
        int j = round-1;
        for (; j >= 0; j--)
        {
            if (arr[j] > val)
            {

                 arr[j + 1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = val;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}