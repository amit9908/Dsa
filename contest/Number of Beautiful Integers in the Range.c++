class Solution {
public:
    int Check(int low) {
        int even = 0;
        int odd = 0;

        while (low > 0)
        {
            if (low % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }

            low /= 10;
        }

        return even == odd ? 1 : 0;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        low = ((low-1)/k + 1) * k;
        int count = 0;
        while (low <= high)
        {
            count += Check(low);
            low += k;

            if (low >= 100000000) return count;
        }
        
        return count;
    }
};