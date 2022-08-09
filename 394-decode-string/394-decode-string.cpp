class Solution {
public:
    string decodeString(string s) {
        string number, repeat_str, ans_str;
        stack<string> st;
        st.push("E");
        int i = 0;
        while(i < s.size()) {
            if('0' <= s[i] and s[i] <= '9') {
                number = "";
                while('0' <= s[i] and s[i] <= '9') {
                    number += s[i];
                    i++;
                }
                st.push(number);
            } else if('a' <= s[i] and s[i] <= 'z') {
                repeat_str = "";
                while('a' <= s[i] and s[i] <= 'z') {
                    repeat_str += s[i];
                    i++;
                }
                ans_str = "";
                while(st.top() != "[" and st.top() != "E") {
                    ans_str = st.top() + ans_str;
                    st.pop();
                }
                st.push(ans_str + repeat_str);
            } else if(s[i] == ']') {
                repeat_str = st.top();
                
                st.pop(); // pop string
                st.pop(); // pop '['
                
                int times  = stoi(st.top());
                st.pop(); // pop number
                
                ans_str = "";
                while(st.top() != "[" and st.top() != "E") {
                    ans_str = st.top() + ans_str;
                    st.pop();
                }
                
                while(times--) ans_str += repeat_str;
                
                st.push(ans_str);
                i++;
            } else {
                st.push("[");
                i++;
            }
        }
        
        return st.top();
    }
};