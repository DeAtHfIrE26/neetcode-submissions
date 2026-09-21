class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(); int m = s2.size();
        if (n > m) return false;
        int cnt[26] = {}; int diff = 0;
        for (char c : s1) if(cnt[c - 'a']++ == 0) diff++;
        for (int r = 0; r < m; r++){
            int in = s2[r] - 'a';
            if(cnt[in] == 0)diff++;
            if(--cnt[in] == 0)diff--;
            if(r >= n){
                int out = s2[r - n] - 'a';
                if(cnt[out] == 0)diff++;
                if(++cnt[out] == 0)diff--;
            }
            if (diff == 0) return true;
        }
        return false;
    }
};
