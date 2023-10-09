class Solution {
public:
    int reverse(long x) {
        stack<int> st;
        bool neg;

        if(x < 0) {
            x *= -1;
            neg = true;
        } else {
            neg = false;
        }

        while(x > 0) {
            st.push(x % 10);
            x /= 10;
        }

        long ans = 0;
        long exp = 1;
        while(!st.empty()) {
            if(st.top() * exp >= numeric_limits<int>::max()) return 0;
            ans += st.top() * exp;
            exp *= 10;
            st.pop();
        }

        if(ans > numeric_limits<int>::max()) {
            return 0;
        }

        return ans * (neg ? -1 : 1);
    }
};