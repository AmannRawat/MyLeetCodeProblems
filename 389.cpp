class Solution {
public:
    char findTheDifference(string s, string t) {
        // int a[26]={0};
        // string A=s+t;
        // char c;
        // for(auto f:A){
        //     c^=f;
        // }

        // map<char,int>freq;
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            // freq[s[i]]++;
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            // freq[t[i]]--;
            freq[t[i]-'a']--;
        }
        // map<char,int>::iterator x=find(freq.begin(),freq.end(),-1);
        vector<int>::iterator x=find(freq.begin(),freq.end(),-1);
    return x-freq.begin()+'a';
    }
};