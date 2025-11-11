#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> arr;
    int num;
    stringstream ss(s);
    while(ss>>num){
        arr.push_back(num);
    }
    for(int n:arr){
        cout<<n<<endl;
    }
    return 0;
}