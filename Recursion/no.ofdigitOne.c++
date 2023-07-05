class Solution {
public:
    int countDigitOne(int n) {
        string temp = to_string(n);
        if(n == 0) return 0;
        if(n < 10) return 1;

        int len = temp.size()-1;
        int base = pow(10 ,len);

        int oneTake = 0;
        int firstDigit = n/base;
        int rem = n%base;

        if(firstDigit != 1){
            oneTake = base;
        }else{
            oneTake = n-base + 1;
        }

        return countDigitOne(rem) + oneTake + firstDigit *countDigitOne(base-1);



    }
};