#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{5, 3, 4, 8, 2, 8};
    int n = arr.size();

    for (int round = 1; round < n; round++)
    {

        for (int j = 0; j < n - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}