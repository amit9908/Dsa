#include <iostream>
#include <vector>

using namespace std;

void solve(string& x , vector<string>& ans  , int index){
    if(index >= x.size()){
        ans.push_back(x);
    }
    
    

    for(int j=index ; j<x.size() ; j++){
        
        swap(x[index] , x[j]);
        solve(x , ans , index+1);
        swap(x[index] , x[j]);
    }
  

}

int main(){
   string x = "azz";
   vector<string> ans;
   solve(x , ans , 0);
   for(int i=0 ; i<ans.size() ; i++){
    cout << ans[i] << endl;
   }
   
   return 0;

}
// t.c o(n!)
// s.c o(n)