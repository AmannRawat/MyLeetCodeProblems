long long getMaxMedian(vector<int>& data, long long k, long long weight) {
    sort(data.begin(), data.end());
    int n = data.size();
    int mid = n / 2;

    long long low = data[mid];
    long long high = data[mid] + k * weight;
    long long ans = low;

    while (low <= high) {
        long long X = low + (high - low) / 2;

        long long ops = 0;
        for (int i = mid; i < n; i++) {
            if (data[i] < X) {
                ops += (X - data[i] + weight - 1) / weight;
            }
        }

        if (ops <= k) {
            ans = X;
            low = X + 1;
        } else {
            high = X - 1;
        }
    }
    return ans;
}
