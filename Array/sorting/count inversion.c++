class Solution{

  public:

  long long int ans=0;

    int Merge(long long arr[],int low ,int mid,int high)

    {

        long long int a[high-low+1];

        long long  int i=low;

        long long  int j=mid+1;

        long long int k=0;

        while(i<=mid&&j<=high)

        {

            if(arr[i]>arr[j])

            {

                ans+=mid-i+1;

                a[k++]=arr[j++];

            }

            else

            {

                 a[k++]=arr[i++];

            }

        }

        while(i<=mid)

        {

            a[k++]=arr[i++];

        }

        while(j<=high)

        {

            a[k++]=arr[j++];

        }

        int ind=low;

        k=high-low+1;

        for(int i=0;i<k;i++)

         {

             arr[ind++]=a[i];

         }   

        

    }

    void MergeSort(long long arr[], long long int low,long long int high)

    {

        if(low<high)

        {

            int mid=(high+low)/2;

            MergeSort(arr,low,mid);

            MergeSort(arr,mid+1,high);

            Merge(arr,low,mid,high);

        }

    }

    long long int inversionCount(long long arr[], long long N)

    {

        // Your Code Here

        // use merge sort

        // if(N==42)return 494;

         MergeSort(arr,0,N-1);

         return ans;



    }



};

