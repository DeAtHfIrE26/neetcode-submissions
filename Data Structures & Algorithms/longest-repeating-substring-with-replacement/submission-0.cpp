class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {}; int maxf = 0; int l = 0;
        for (int r = 0; r < s.size(); r++){
            maxf = max(maxf, ++count[s[r] - 'A']);
            if (r - l + 1 - maxf > k ) count[s[l++] - 'A']--;
        }
        return s.size() - l;
    }
};
