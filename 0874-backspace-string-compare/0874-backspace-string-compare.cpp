class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a;
        string b;

        int k = 0;
        for(auto c : s) {
            if(c == '#') {
                if(a.size() != 0) a.pop_back();
            } else {
                a += c;
            }
        }
        for(auto c : t) {
            if(c == '#') {
                if(b.size() != 0) b.pop_back();
            } else {
                b += c;
            }
        }

        cout << a << endl;
        cout << b << endl;

        return a == b;
    }
};