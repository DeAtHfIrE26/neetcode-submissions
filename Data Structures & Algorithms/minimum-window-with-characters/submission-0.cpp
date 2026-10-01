class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> need(128,0);
        for (char c : t) ++need[c];

        int missing = t.size();
        int bestLen = INT_MAX, bestStart = 0;

        for (int l = 0,r = 0; r < (int)s.size(); r++){
            if (need[s[r]]-- > 0) --missing;

            while(missing == 0){
                if (r - l + 1 < bestLen){
                    bestLen = r - l + 1;
                    bestStart = l;
                }
                if (++need[s[l++]] > 0) ++missing;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
