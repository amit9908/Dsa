class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        for(int i=0 ; i<timePoints.size() ; i++){
            string curr = timePoints[i];

            int hour= stoi(curr.substr(0,2));
            int minute = stoi(curr.substr(3,2));
            int totalminute = 60*hour + minute;
            minutes.push_back(totalminute);
        }

        sort(minutes.begin() , minutes.end());
        int mini=INT_MAX;
        for(int i=0 ; i<minutes.size()-1 ; i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini , diff);
        }
        int lastdiff1 = (minutes[0]+1440)-minutes[minutes.size()-1];
        int lastdiff2 = minutes[minutes.size()-1] - minutes[0];
        int lastdiff = min(lastdiff1 , lastdiff2);
        mini = min(mini , lastdiff);
        return mini;
        
    }
};