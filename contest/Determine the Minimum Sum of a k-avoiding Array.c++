class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>s;
        int a=1,sum=0;
        while(s.size()!=n){
            if(!s.count(k-a)){
            s.insert(a);
            sum+=a;
            }
            a++;
        }
        return sum;
    }
};