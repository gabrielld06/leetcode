class Solution {
public:
    int calc(int x, int y, string op) {
        if(op == "+") {
            return x + y;
        } else if(op == "-") {
            return x - y;
        } else if(op == "*") {
            return x * y;
        } else {
            return x / y;
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto c : tokens) {
            if(c == "+" or c == "-" or c == "*" or c == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                st.push(calc(b, a, c));
            } else {
                st.push(stoi(c));
            }
        }
        
        return st.top();
    }
};