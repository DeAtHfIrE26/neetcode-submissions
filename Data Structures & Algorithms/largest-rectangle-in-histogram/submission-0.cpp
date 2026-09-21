class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int>st = {-1};
        int best = 0;

        for (int i = 0; i < heights.size(); i++){
            while(st.back() != -1 && heights[i] < heights[st.back()]){
                int H = heights[st.back()]; st.pop_back();
                best = max(best, H * ( i - st.back() - 1));
            }
            st.push_back(i);
        }
        heights.pop_back();
        return best;
    }
};
