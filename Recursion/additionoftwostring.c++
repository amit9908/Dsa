#include<iostream>
#include<vector>
using namespace std;

void solve(string &a , string &b, int i  , int j ,int carry , string &ans){
    
    if(i < 0  && j < 0 && carry == 0){
       return ;
    }

    int first = 0;
    int second = 0;
    if(i>=0) first = a[i] - '0';
    if(j>=0) second = b[j] - '0';

    int sum = first + second + carry;
    int lastdigit = sum%10;
     carry = sum/10;

    ans.push_back(lastdigit + '0');
    solve(a,b,i-1 ,j-1,carry,ans);



}   

int main(){

    string a = "123";
    string b = "786"; 

    string ans = "";
    

    //vector<string> output;
   
   solve(a , b , a.length()-1  , b.length()-1 , 0 , ans);

   int i=0;
   int j=ans.length()-1;
   while(i<=j){
    swap(ans[i] , ans[j]);
    i++;
    j--;
   }

   cout<<ans<<endl;


}