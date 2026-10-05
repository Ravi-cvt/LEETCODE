class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int max_len = 0;
        for (int muc = 1; muc <= 26; ++muc) {
            vector<int> freq(26, 0);
            int l = 0, r = 0;
            int unique = 0;
            int countAtLeastK = 0;
            
            while (r < n) {
                int index = s[r] - 'a';
                if (freq[index] == 0) {
                    unique++;
                }
                freq[index]++;
                if (freq[index] == k) {
                    countAtLeastK++;
                }
                while (unique > muc) {
                    int leftIndex = s[l] - 'a';
                    if (freq[leftIndex] == k) {
                        countAtLeastK--;
                    }
                    freq[leftIndex]--;
                    if (freq[leftIndex] == 0) {
                        unique--;
                    }
                    l++;
                }
                if (unique == muc && unique == countAtLeastK) {
                    max_len = max(max_len, r - l + 1);
                }
                r++;
            }
        }
        
        return max_len;
    }
};