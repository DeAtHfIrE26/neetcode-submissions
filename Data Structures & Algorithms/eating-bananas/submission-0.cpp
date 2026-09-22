class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());

        while(l < r){
            int x = l + (r - l) / 2;
            long long hours = 0;

            for (int p : piles){
                hours += (p + x - 1) / x;    
            }
            if (hours <= h) r = x;
            else l = x + 1;
        }
        return l;
    }
};
