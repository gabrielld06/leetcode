class Solution {
public:
    string multiply(string num1, string num2) {
        if(num2.length() > num1.length() ) {
            string aux = num1;
            num1 = num2;
            num2 = aux;
        }
        if(num1 == "0" or num2 == "0") return "0";
        string ans = "";
        int cin = 0;
        stack<string> st;
        st.push("-1");
        
        for(int i = num2.length()-1;i>=0;i--) {
            ans = "";
            cin = 0;
            for(int j = num1.length()-1;j>=0;j--) {
                int num = ((num1[j] - '0') * (num2[i] - '0') + cin);
                cin = num/10;
                num = num % 10;
                char n = num + '0';
                ans = n + ans;
            }
            while(cin != 0) {
                char c = cin + '0';
                ans = c + ans;
                cin = cin/10;
            }
            st.push(ans);
        }
        int i = num2.length()-1;
        ans = st.top() + string(i, '0');
        st.pop();
        i--;
        string sum;
        while(st.top() != "-1") {
            sum = st.top() + string(i, '0');
            cin = 0;
            int j, k;
            for(j = sum.length()-1, k = ans.length()-1;j >=0;j--, k--) {
                int num = ((ans[k] - '0') + (sum[j] - '0') + cin);
                cin = num/10;
                num = num % 10;
                char n = num + '0';
                ans[k] = n;
            }
            while(k >= 0 and cin != 0) {
                int num = (ans[k] - '0') + cin;
                cin = num/10;
                num = num % 10;
                char n = num + '0';
                ans[k] = n;
                k--;
            }
            while(cin != 0) {
                char c = cin + '0';
                ans = c + ans;
                cin = cin/10;
            }
            st.pop();
            i--;
        }
        
        return ans;
    }
};