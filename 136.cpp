class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //      map<int,int> m;
    //      int ans;
    //       for(int i=0;i<nums.size();i++){
    //         m[nums[i]]++;
    //     }
    //     for(auto& x:m){
    //         if(x.second%2 !=0)
    //             ans=x.first;
    //     }
    // return ans;
    int x=0;
    for(int i=0;i<nums.size();i++){
        x=x^nums[i];
    }
    return x;
    }
};