//lis variation
class Solution {
public:
	int maxh(int i,int prev,vector<vector<int>>& cubo,int n){
		if(i==n) return 0;
		int pick=INT_MIN;
		if(prev==-1 || (cubo[prev][1]<=cubo[i][1] && cubo[prev][2]<=cubo[i][2])){
			pick=cubo[i][2]+maxh(i+1,i,cubo,n);
		}
		int notpick=maxh(i+1,prev,cubo,n);
		return max(pick,notpick);
	}

	int maxHeight(vector<vector<int>>& cubo) {
		int n=cubo.size();
		for(auto &i:cubo) sort(i.begin(),i.end());
		sort(cubo.begin(),cubo.end());
		return maxh(0,-1,cubo,n);
	}
};