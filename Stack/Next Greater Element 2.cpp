class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); //Learning 1 : Smart work

        for(int i = 0; i < n; i++){
            int j = (i + 1) % n; //Learning 2 : How to simulate Circular 
            while(j != i){
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    break;
                }
                j = (j + 1) % n;
            }
        }
        return ans;
    }
};

//Optimized Approach using Stack O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Learning 1 : Smart work
        stack<int> s;
        for (int i = (2 * n) - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            if (i < n) {
                ans[i] = s.empty() ? -1 : s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};
