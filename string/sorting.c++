#include <bits/stdc++.h>
using namespace std;

bool cmp(char a , char b){
    return a > b;
}

int main(){
    string name = "amit";
    sort(name.begin() , name.end(), cmp);
    cout << name << "";
}