#include <iostream>
using namespace std;

void mergesort(int arr, int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int i = 0;
    for (int index = s; index < mid; index++)
    {
        first[i] = arr[index];
        i++;
    }

    int j = 0;
    for (int index = mid ; index < e; index++)
    {
        second[j] = arr[index];
        j++;
    }

    int OrginalIndex = s;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[OrginalIndex] = first[index1];
            index1++;
            OrginalIndex++;
        }
        else
        {
            arr[OrginalIndex] = second[index2];
            index2++;
            OrginalIndex++;
        }
    }

    while (index1 < len1)
    {
        arr[OrginalIndex] = first[index1];
        index1++;
        OrginalIndex++;
    }

    while (index2 < len2)
    {
        arr[OrginalIndex] = second[index2];
        index2++;
        OrginalIndex++;
    }
}

void sort(int arr, int s, int e)
{
    if (s >= e) return;


    int mid = s + (e - s) / 2;


    sort(arr, s, mid);
    sort(arr, mid + 1, e);
    mergesort(arr, s, mid, e);
}

int main()
{
    int arr[] = {2, 8, 9, 0, 1, 3};
    int size = 6;
    sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}

// t.c 0(nlogn)
// s.c O(logn);