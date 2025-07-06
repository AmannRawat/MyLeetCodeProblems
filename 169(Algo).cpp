// MY approach  TC O(n) Space Complexity O(n)
class Solution {
    public:
    #include <bits/stdc++.h>
    int majorityElement(vector<int>& arr) {
        unordered_map <int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }
        int maxi = -1, idx = 0;
        for (auto i : mpp) {
            if (maxi < i.second) {
                maxi = i.second;
                 idx = i.first;
            }
        }
        return idx;
        // For n / 2 condition
        //   for (auto it : mpp) {
        //     if (it.second > n / 2) {
        //         return it.first;
        //     }
        // }
        // return -1; 
    }
};

//Optimal approach with TC O(n) Space Complexity O(1)  BOYR MOOR's Majority Voting Element Algorithm 
class Solution {
public:
    // BOYER MOOR's VOTING ALGORITM
    int majorityElement(vector<int>& arr) {
        int count=0,elm,n=arr.size();
        for (int i = 0; i < n; i++) {
            if(count==0){
                elm=arr[i];
                count++;
            }else if(elm==arr[i]) count++;
            else count--;
        }
        int counter=0;
         for (int i = 0; i < arr.size(); i++){
            if (arr[i]==elm) counter++;
        }
        if(counter>n/2) return elm;
        return -1;
    }
};