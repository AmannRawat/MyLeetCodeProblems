#include<bits/stdc++.h>
using namespace std;
int main(){
    int no;
    cin>>no;
    cin.ignore();
    string s;
    // cin>>s;
    getline(cin, s);
    vector<int> arr;
    int num;
    stringstream ss(s);
    string word;
    cout<<no<<endl;
    while(getline(ss, word, ',')){
        num=stoi(word);
        arr.push_back(num);
    }
    for(int n:arr){
        cout<<n<<endl;
    }
    return 0;
}