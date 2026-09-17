class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>st;

        for (string& t : tokens){
            if (t.size() > 1 || isdigit(t[0])){
                st.push_back(stoi(t));
            }
            else{
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();

                switch(t[0]){
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    default : st.push_back(a / b); break;
                }
            }
        }
        return st.back();
    }
};
