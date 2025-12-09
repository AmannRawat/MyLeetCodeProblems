class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int &n: nums1){
            int i = 0;

            // Find n in nums2
            while (i < nums2.size() && nums2[i] != n) i++;

            int original = n; 
            n = -1;            
            while (++i < nums2.size()) {
                if (nums2[i] > original) {
                    n = nums2[i];
                    break;
                }
            }
        }
        return nums1;
    }
};

//Optimized Approach using Stack O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            next[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back(next[num]);
        }
        return res;
    }
};