class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0), st;

        for (int i = 0; i < n; i++){
            while (!st.empty() && temperatures[i] > temperatures[st.back()]){
                int j = st.back(); st.pop_back();
                result[j] = i - j;
            }
            st.push_back(i);
        }
        return result;
    }
};
