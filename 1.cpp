// Brute force O(n2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int brk = 0;
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    brk = 1;
                    break;
                }
            }
            if (brk)
                break;
        }
        return indices;
    }
};

// Better approach O(n logn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num, more;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            num = nums[i];
            more = target - num;
            if (mpp.find(more) != mpp.end()) //Instead of this we can use "if (mpp.count(more))" also works perfectly for just checking existence
                return {mpp[more], i};

            mpp[num]=i;
        }
        return {-1, -1};
    }
};