class Solution {
public:
    bool checkBoquests(vector<int>& b, int days, int adjFlow, int boque) {
        int n = b.size();
        int k = 0, m = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] <= days) {
                k++;
                if (k == adjFlow) {
                    m++;
                    k = 0;
                }
            } else {
                k = 0;
            }
        }
       return m >= boque;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long totalboquets= (long long)m*k;
        if (n < totalboquets)
            return -1;

        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        long long low = mini, high = maxi, mid;
        while (low <= high) {
            mid = (high + low) / 2;
            if (checkBoquests(bloomDay, mid, k, m))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};