class Solution
{
	public:
	    void solve(string& s , vector<string>& ans  , int index){
	        if(index >= s.length()){
	            ans.push_back(s);
	            return;
	        }
	        
	        unordered_set<int> st;
	        for(int j=index ; j<s.size() ; j++){
	            if(st.find(s[j]) != st.end()) continue;
	            st.insert(s[j]);
	            
	            swap(s[index] , s[j]);
	            solve(s , ans , index+1);
	            swap(s[index],s[j]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    solve(S,ans,0);
		    sort(ans.begin() , ans.end());
		    return ans;
		}
};

