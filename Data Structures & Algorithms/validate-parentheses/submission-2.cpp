class Solution {
public:
    bool isValid(string s) {
        string st;

        for (char x : s){
            if (x == '(' || x == '[' || x == '{') st += x;
            else{
                if (st.empty()) return false;
                char t = st.back();
                if ( (x == ')' && t != '(') || (x == ']' && t != '[') || (x == '}' && t != '{')) return false;
                st.pop_back();
            }

        }
        return st.empty();
    }
};
