#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int num;
    getline(cin, s);
    int star=0, hash=0;
    for(char c:s){
        if(c=='*')star++;
        else if(c=='#')hash++;
    }
   cout<<star-hash<<endl;
    return 0;
}
