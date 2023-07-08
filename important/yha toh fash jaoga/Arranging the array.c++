class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int>v1;
            vector<int>v2;


            for(int i=0;i<n;i++)
            {
                if(arr[i]>=0) v1.push_back(arr[i]);
                else v2.push_back(arr[i]);
            }


            for(int i=0;i<v2.size();i++)
            {
                arr[i]=v2.at(i);
            }


            for(int i=v2.size(),j=0;i<n;i++,j++)
            {
                arr[i]=v1.at(j);
            }
        }
};