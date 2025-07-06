// My apporoach (Brute Force) O(n*k)
class Solution {
public:
    void rotate(vector<int>& n, int k) {
        int size=n.size();
         k = k % size;
        for (int i = 0; i < k; i++) {
            int last = n[size - 1]; 
            for (int j = size-1; j > 0; j--){
                n[j]=n[j-1];
            }
            // n[0]=n[n.size()-1];
            n[0]=last;
        }
    }
};

// Better Approach O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        //Below Logic is for rotating right side
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
         //Below Logic is for rotating left side
        reverse(nums.begin(), nums.begin() + k);       // Reverse first k
        reverse(nums.begin() + k, nums.end());         // Reverse the rest
        reverse(nums.begin(), nums.end());             // Reverse whole array
    }
};
