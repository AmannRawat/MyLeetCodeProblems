class Solution {
public:

    long long merge(vector<int> &a, int start, int mid, int end) {
         long long count = 0;
        int i = start, j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= end) {
            if (a[i] <= a[j]) {
                temp.push_back(a[i++]);
            } else {
                temp.push_back(a[j++]);
                count += (mid - i + 1);
            }
        }

        while (i <= mid) temp.push_back(a[i++]);
        while (j <= end) temp.push_back(a[j++]);

        for (int k = 0; k < temp.size(); k++) {
            a[start + k] = temp[k];
        }
        return count;
    }

    long long divNRule(vector<int> &a, int start, int end) {
         long long count = 0;
        if (start < end) {
            int mid = start + (end - start) / 2;
            count+=divNRule(a, start, mid);
            count+=divNRule(a, mid + 1, end);
            count+=merge(a, start, mid, end);
        }
        return count;
    }

    long long inversionCount(vector<int> &arr) {
        long long count = 0;
        count=divNRule(arr, 0, arr.size() - 1);
        return count;
    }
};
