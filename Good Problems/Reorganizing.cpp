class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxfreq = 0;
        char maxChar;
        for (char c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > (n + 1) / 2) // ceil(n/2)
                return "";
            if (freq[c - 'a'] > maxfreq) {
                maxfreq = freq[c - 'a'];
                maxChar = c;
            }
        }

        string result = s;
        int i = 0;
        while (freq[maxChar - 'a'] > 0) {
            result[i] = maxChar;
            i = i + 2;
            freq[maxChar - 'a']--;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            while (freq[ch - 'a'] > 0) {
                if (i >= n)
                    i = 1;
                result[i] = ch;
                i = i + 2;
                freq[ch - 'a']--;
            }
        }
        return result;
    }
};
