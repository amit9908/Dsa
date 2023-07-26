class Solution {
public:
    double possible(vector<int>& dist, int mid_speed){
      double time = 0.0;
      int n = dist.size();

      for(int i=0; i<n-1 ; i++){
          double t = (double)dist[i] / (double)mid_speed;
          time += ceil(t);
      }
      time +=  (double)dist[n-1] / (double)mid_speed;
      return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;

        int midSpeed = -1;
        int result = -1;

        while(l <= r){
            int mid_Speed = l + (r-l)/2;
            if(possible(dist , mid_Speed) <= hour){
                result = mid_Speed;
                r = mid_Speed-1;
            }else{
                l = mid_Speed+1;
            }
        } 
        return result;
    }
};