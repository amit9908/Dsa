class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> a = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ans="";
        for(int i=0;i<a.size();i++){
            while(num>=a[i].first){
                ans+=a[i].second;
                num-=a[i].first;
            }
        }
        return ans;
    }
};



